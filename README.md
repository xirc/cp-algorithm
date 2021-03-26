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

* [Disjoint Set Union](/lib/cpalgo/ds/README.md#Disjoint-Set-Union)
* [Binary Indexed Tree](/lib/cpalgo/ds/README.md#Binary-Indexed-Tree)
* [Minimum Queue](/lib/cpalgo/ds/README.md#Minimum-Queue)
* [Minimum Stack](/lib/cpalgo/ds/README.md#Minimum-Stack)
* [Randomized Heap](/lib/cpalgo/ds/README.md#Randomized-Heap)
* [Segment Tree](/lib/cpalgo/ds/README.md#Segment-Tree)
* [Sqrt Decomposition](/lib/cpalgo/ds/README.md#Sqrt-Decomposition)
* [Sparse Table](/lib/cpalgo/ds/README.md#Sparse-Table)
* [Disjoint Sparse Table](/lib/cpalgo/ds/README.md#Disjoint-Sparse-Table)
* [Treap](/lib/cpalgo/ds/README.md#Treap)
* [Implicit Treap](/lib/cpalgo/ds/README.md#Implicit-Treap)
* [kD Tree (n-dimensional)](/lib/cpalgo/ds/README.md#kD-Tree)

### [Tree](/lib/cpalgo/tree/README.md)

* [Diameter](/lib/cpalgo/tree/README.md#Diameter)
* [Euler Tour](/lib/cpalgo/tree/README.md#Euler-Tour)
* [Heavy Light Decomposition](/lib/cpalgo/tree/README.md#Heavy-Light-Decomposition)
* [Height](/lib/cpalgo/tree/README.md#Height)
* [Lowest Common Ancestor](/lib/cpalgo/tree/README.md#Lowest-Common-Ancestor)

### [Graph](/lib/cpalgo/graph/README.md)

* [Articulation Points](/lib/cpalgo/graph/README.md#Articulation-Points)
* [Bridges](/lib/cpalgo/graph/README.md#Bridges)
* [Topological Sort](/lib/cpalgo/graph/README.md#Topological-Sort)
* [Strongly Connected Components](/lib/cpalgo/graph/README.md#Strongly-Connected-Components)
* Single-Source Shortest Path
  * [Dijkstra](/lib/cpalgo/graph/README.md#Dijkstra)  
    Support Only Positive Weights
  * [Bellman-Ford](/lib/cpalgo/graph/README.md#Bellman-Ford)  
    Support Negative Weights
  * [SPFA](/lib/cpalgo/graph/README.md#SPFA)  
    Support Negative Weights
* All-Pairs Shortest Path
  * [Floyd-Warshall](/lib/cpalgo/graph/README.md#Floyd-Warshall)
* Bipartite
  * [Bipartite Check](/lib/cpalgo/graph/README.md#Bipartite-Check)
  * [Bipartite Maximum Matching](/lib/cpalgo/graph/README.md#Bipartite-Maximum-Matching)
* Cycle
  * [Finding Cycle](/lib/cpalgo/graph/README.md#Finding-Cycle)
  * [Finding Negative Cycle](/lib/cpalgo/graph/README.md#Finding-Negative-Cycle)
    * Floyed-Warshall
    * Bellman-Ford
* [Minimum Spanning Tree](/lib/cpalgo/graph/README.md#Minimum-Spanning-Tree)
* [Minimum Cost Arborescence](/lib/cpalgo/graph/README.md#Minimum-Cost-Arborescence)
* [Maximum Flow](/lib/cpalgo/graph/README.md#Maximum-Flow)
  * Dinic
  * Edmonds-Karp
  * MPM
  * Push Relabel (Generic)
  * Push Relabel (Highest)
* [Minimum Cut](/lib/cpalgo/graph/README.md#Minimum-Cut)
* [Minimum Cost Flow](/lib/cpalgo/graph/README.md#Minimum-Cost-Flow)

### [Utilities](/lib/cpalgo/util)

* [Binary Search](/lib/cpalgo/util/README.md#Binary-Search)
* [Two Pointers](/lib/cpalgo/util/README.md#Two-Pointers)  
  "しゃくとり法" in Japanese
* [BigInt](/lib/cpalgo/util/README.md#BigInt)
* [Dice](/lib/cpalgo/util/README.md#Dice)

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