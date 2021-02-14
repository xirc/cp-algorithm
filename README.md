# Competitive Programming Library

[![CircleCI](https://circleci.com/gh/xirc/cp-algorithm.svg?style=shield)](https://circleci.com/gh/xirc/cp-algorithm)

This project contains my competitive programming library, examples, and solutions.


## Library

### [Algebra](/lib/cpalgo/algebra/README.md)

* [Greatest Common Divisor](/lib/cpalgo/algebra/README.md#Greatest-Common-Divisor)
* [Least Common Multiple](/lib/cpalgo/algebra/README.md#Least-Common-Multiple)
* [Binary Exponentiation](lib/cpalgo/algebra/README.md#Binary-Exponentiation)
* [Prime Factorization](lib/cpalgo/algebra/README.md#Prime-Factorization)
* [Binomial Coefficients](lib/cpalgo/algebra/README.md#Binomial-Coefficients)
* [Extended Euclidean Algorithm](lib/cpalgo/algebra/README.md#Extended-Euclidean-Algorithm)

### [Geometry (2D)](/lib/cpalgo/geometry)

* Basic Operations
* Projection, Rejection
* CCW
* Line
  * Orthogonal
  * Parallel
* Intersection
  * Line-Point
  * Segment-Point
  * Line-Line
  * Segment-Segment
  * Line-Segment (w/o point)
  * Circle-Circle
  * Circle-Line
* Distance
  * Line-Point
  * Segment-Point
  * Line-Line
  * Segment-Segment
  * Line-Segment
* Polygon
  * Area
  * Convex Check
  * Containment (ON, IN, OUT)
  * Convex Hull
  * Convex Diameter
* Circle
  * Tangent Line
    - Circle-Point
    - Circle-Circle
* Line Sweep
  * Distance of the Closest Pair
  * Segment Intersections in Manhattan Geometry
  * Area of Union Rectangles

### [Geometry (3D)](/lib/cpalgo/geometry)

* Basic Operations
* Projection, Rejection

### [Data Structures](/lib/cpalgo/ds)

* Binary Indexed Tree (Fenwick Tree)
* Cartesian Tree
* Disjoint Sparse Table
* Heap
* Implicit Treap
* Queue
* Segment Tree
* Sparse Table
* Sqrt Decomposition
* Stack
* Treap
* Union Find Tree (Disjoint Set Union)
* kD Tree (n-dimensional)

### [Tree](/lib/cpalgo/tree/README.md)

* [Diameter](/lib/cpalgo/tree/README.md#Diameter)
* [Euler Tour](/lib/cpalgo/tree/README.md#Euler-Tour)
* [Heavy Light Decomposition](/lib/cpalgo/tree/README.md#Heavy-Light-Decomposition)
* [Height](/lib/cpalgo/tree/README.md#Height)
* [Lowest Common Ancestor](/lib/cpalgo/tree/README.md#Lowest-Common-Ancestor)

### [Graph](/lib/cpalgo/graph)

* Articulation Points
* Bellman Ford  
  Single Source Shortest Path (with Negative Weight)
* Bipartite
  * Check
  * Matching
* Bridges
* Dijkstra  
  Single Source Shortest Path (with Only Positive Weight)
* Finding Cycle
* Floyd Warshall  
  All Pairs Shortest Path
* Minimum Spanning Tree
* Minimum Cost Arborescence
* Maximum Flow  
  * Dinic
  * Edmonds-Karp
  * MPM
  * Preflow Push Relabel (generic)
  * Preflow Push Relabel (highest)
* Minimum Cost Flow
* Finding Negative Cycle
  * Bellman Ford
  * Floyd Warshall
* Strongly Connected Components
* Topological Sort

### [Utilities](/lib/cpalgo/util)

* bigint  
  Big Integer (not well-tested)
* dice
* two pointers  
  "しゃくとり法" in Japanese


## How to provision development environment

Use [Visual Studio Remote Containers*](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

## How to build library and examples

See [lib/README.md](lib/README.md)


## References

* [cplusplus.com](http://www.cplusplus.com/reference/)

## Learning sites

* [Topcoder Competitive Programming Tutorials](https://www.topcoder.com/community/competitive-programming/tutorials/)
* [E-Maxx Algorithms in English](https://cp-algorithms.com/)
* [Top 10 Algorithms and Data Structures for Competitive Programming | GeekforGeeks](https://www.geeksforgeeks.org/top-algorithms-and-data-structures-for-competitive-programming/)
* [SecondThread](https://www.youtube.com/channel/UCXbCohpE9IoVQUD2Ifg1d1g?)
* [アルゴリズムロジック](https://algo-logic.info/)
* [各種アルゴリズムの C++ による実装](http://www.prefield.com/algorithm/)


## Tips

### GCC Compiler Flags

It would be better to use the following compiler flags.
In the _Visual Studio Code Remote Container_ environment,
the flags are used as default by the command alias. See [Dockerfile](/.devcontainer/Dockerfile).


- `-D_GLIBCXX_DEBUG`  
See [Macros](https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_macros.html)

- `-fsanitize=undefined`  
See [Program Instrumentation Options](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)