// https://www.spoj.com/problems/AKBAR/

#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> knight_of_city;

void init(int N) {
    graph.assign(N, vector<int>());
    knight_of_city.assign(N, -1);
}
bool place(int N, int source, int max_distance) {
    queue<pair<int,int>> Q;
    Q.push({source,0});
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int index = cur.first, distance = cur.second;
        if (knight_of_city[index] == source) {
            continue;
        }
        if (knight_of_city[index] != -1) {
            return false;
        }
        knight_of_city[index] = source;
        if (distance >= max_distance) {
            continue;
        }
        for (auto i : graph[index]) {
            Q.push({i,distance+1});
        }
    }
    return true;
}
bool are_all_protected(int N) {
    for (int i = 0; i < N; ++i) {
        if (knight_of_city[i] == -1) return false;
    }
    return true;
}

int main() {
    int T, N, R, M;
    
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d %d", &N, &R, &M);
        init(N);
        for (int r = 0; r < R; ++r) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a, --b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool ans = true;
        for (int m = 0; m < M; ++m) {
            int k, s;
            scanf("%d %d", &k, &s);
            k--;
            if (ans) {
                ans &= place(N, k, s);
            }
        }
        ans &= are_all_protected(N);
        printf(ans ? "Yes\n" : "No\n");
    }

    return 0;
}