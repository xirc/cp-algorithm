# Graph Algorithms

## Articulation Points
An articulation Point (or a cut vertex) is a vertex.
If we remove the vertex from a graph, it makes the graph disconnected.
A graph may have zero or more articulation points.
We can find all articulation points of a given graph in `O(V + E)`.
`V` is the number of nodes. `E` is the number of edges.

![Articulation Points](resources/articulation_points.drawio.svg)

[Articulation Points | C++ code](articulation_points.hpp)

## References in English
- [Finding articulation points in a graph in O(N+M) | E-Maxx Algorithms in English](https://cp-algorithms.com/graph/cutpoints.html)

### Challenges
- [Articulation Points | AOJ GRL3A](https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A)


## Bridges
🚧


## Topological Sort
🚧

### Challenges
- [AtCoder | E - League](https://atcoder.jp/contests/abc139/tasks/abc139_e)


## Strongly Connected Components
🚧


## Single-Source Shortest Paths

### Dijkstra
🚧

### Bellman-Ford
🚧

### SPFA
🚧

### Challenges
- [トレジャーハント - AtCoder ABC035D](https://atcoder.jp/contests/abc035/tasks/abc035_d)


## All-Pairs Shortest Paths

### Floyd-Warshall
🚧

### Challenges
- [正直者の高橋くん - AtCoder ABC021C](https://atcoder.jp/contests/abc021/tasks/abc021_c)
- [Blue Bird - AtCoder ABC022C](https://atcoder.jp/contests/abc022/tasks/abc022_c)
- [Travel by Car - AtCoder ABC143E](https://atcoder.jp/contests/abc143/tasks/abc143_e)

## Bipartite

### Bipartite Check
Check whether a given graph is bipartite or not.
It can be computed in `O(V)`.
`V` is the number of vertices.

[Bipartite Check | C++ code](bipartite/bipartite_check.hpp)

### Bipartite Maximum Matching
Find the maximum matching in a given bipartite graph `G`.
Kuhn's algorithm can compute the maximum matching in `O(VE)`.
`V` is the number of vertices. `E` is the number of edges.

[Bipartite Maximum Matching | C++ code](bipartite/bipartite_maximum_matching.hpp)

#### References in English
- [Kuhn's Algorithm for Maximum Bipartite Matching - Competitive Programming Algorithms](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)

#### Challenges
- [GRL_7_A < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A)
- [C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)


## Cycle

### Finding Cycle
🚧

### Finding Negative Cycle
🚧


## Minimum Spanning Tree
🚧


## Minimum Cost Arborescence
🚧


## Maximum Flow
🚧


## Minimum Cut
🚧


## Minimum Cost Flow
🚧