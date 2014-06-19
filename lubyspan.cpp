#include "common.hpp"
#include <random>

DEFINE_int32(scale, 3, "Log2 number of vertices.");
DEFINE_int32(edgefactor, 2, "Average edges per vertex.");

std::default_random_engine randengine;
std::uniform_int_distribution<unsigned int> distrib;

// level: 0 indicates not candidate not in set
// 	  1 indicates candidate
// 	 -1 indicates discarded
// 	  2 indicates accepted

inline bool stillVertices(GlobalAddress<Graph<BFSVertex>> g) {
 bool notDone = false;
 forall(g, [&notDone](BFSVertex &v) {
    if(v->level == 0) {
      notDone = true;
    }
  });
  return notDone;
}

/*inline bool spanning(GlobalAddress<Graph<BFSVertex>> g) {
  forall(g, [g](BFSVertex &v) {
    if (v->level == 2) {
      v->seen = true;
      forall<async>(adj(g, v), [](BFSVertex &vj) {
        vj->seen = true;
      });
    }
  });

  bool ret = true;
  forall(g, [&ret] (BFSVertex &v) {
    if (!v->seen) {
      ret = false;
    }
  });

  return ret;
}*/

int main(int argc, char * argv[]) {
  init(&argc, &argv);
  run([] {

    int64_t NE = (1L << FLAGS_scale) * FLAGS_edgefactor;
    auto tg = TupleGraph::Kronecker(FLAGS_scale, NE, 111, 222);
    auto g = Graph<BFSVertex>::create(tg);

    forall(g, [](BFSVertex& v) {
      v->init();
      v->level = 0;
    });

    do {
      forall(g, [](BFSVertex &v) {
        if (v->level == 0 && (v.nadj == 0 || distrib(randengine) % (2 * v.nadj) == 0)) {
          v->level = 1; // candidate
        }
      });

      forall(g, [g](BFSVertex &v) {
        if (v->level == 1) {
          int64_t nadj = v.nadj;
          auto gv = make_global( &v );
          forall<async>(adj(g, v), [nadj, gv](GlobalAddress<BFSVertex> vj) {
            bool discard = delegate::call(vj, [nadj](BFSVertex &l) {
              if(l->level == 2 || (l->level == 1 && l.nadj > nadj)) {
                return true;
              } else if (l->level == 1) {
                l->level = -1;
                return false;
              }
            });

            if(discard) {
              delegate::call<async>( gv, []( BFSVertex &x ) { x->level = -1; } );
            }
          });
        }
        if (v->level == 1) {
          v->level == 2;
        }
      });
    } while (stillVertices(g));

    //bool print = spanning(g);
      forall(g, [g](BFSVertex &v) {
          v->seen = true;
          forall<async>(adj(g, v), [](GlobalAddress<BFSVertex> vj) {
            delegate::call(vj, [](BFSVertex &l) {
              l->seen = true;
            });
          });
      });

    /*forall(g, [g](BFSVertex &v) {
      if (v->level == 2) {
        v->seen = true;
        forall<async>(adj(g, v), [](GlobalAddress<BFSVertex> &vj) {
          delegate::call(vj, [](BFSVertex &l) {
            l->seen = true;
          });
        });
      }
    });*/

    bool spanning = true;
    forall(g, [&spanning](BFSVertex &v) {
      if (v->seen == false) {
        spanning = false;
      }
    });

    if(spanning) {
      LOG(INFO) << "Yay! Spanning maybe.";
    } else {
      LOG(INFO) << "Not actually a spanning set";
    }

    tg.destroy();
    g->destroy();
  });
  finalize();
}
