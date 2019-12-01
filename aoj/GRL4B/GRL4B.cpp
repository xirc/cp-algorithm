// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

vector<int> solve(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> in(V);
    vector<int> ans;
    stack<int> cs;

    // O(V)
    for (int s = 0; s < V; ++s) {
        for (int t : G[s]) {
            in[t]++;
        }
    }

    // O(V)
    for (int i = 0; i < V; ++i) {
        if (in[i] == 0) {
            cs.push(i);
        }
    }

    // O(E)
    while (!cs.empty()){
        int c = cs.top(); cs.pop();
        ans.push_back(c);
        for (int d : G[c]) {
            in[d] -= 1;
            if (in[d] == 0) {
                cs.push(d);
            }
        }
    }

    return ans;
}

const int MAX_V = 10000;
const int MAX_E = 100000;

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    vector<vector<int>> G(V);
    for (int i = 0; i < V; ++i) {
        G[i] = vector<int>();
    }
    for (int i = 0; i < E; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }

    auto ans = solve(G);
    for (int v : ans) {
        printf("%d\n", v);
    }

    return 0;
}