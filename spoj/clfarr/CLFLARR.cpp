// https://www.spoj.com/problems/CLFLARR/

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200000;
int next_elements[N];
int colors[N];

struct Query { int l; int r; int c; };
const int Q = 200000;
Query queries[Q];

// clear all
void clear() {
    for (int i = 0; i < N; ++i) {
        next_elements[i] = i;
        colors[i] = 0;
    }
}

// find the next right(or self) unpainted element
int find(int x) {
    if (x >= N || next_elements[x] == x) {
        return x;
    }
    next_elements[x] = find(next_elements[x]);
    return next_elements[x];
}

// paint elements in range [l, r) to c
void paint(int l, int r, int c) {
    for (int v = find(l); v < r && v < N; v = find(v)) {
        next_elements[v] = v + 1;
        colors[v] = c;
    }
}

int main() {
    int n, q;
    int l, r, c;
    
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &l, &r, &c);
        --l; --r;
        queries[i] = Query { l, r + 1, c };
    }

    clear();
    for (int i = q -1; i >= 0; --i) {
        auto query = queries[i];
        paint(query.l, query.r, query.c);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", colors[i]);
    }

    return 0;
}