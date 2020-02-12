// https://codeforces.com/contest/653/problem/B

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N, Q;
map<string,string> ops;

int solve() {
    vector<set<string>> inv(6);
    for (auto kv : ops) {
        int i = kv.second[0] - 'a';
        inv[i].insert(kv.first);
    }

    int ans = 0;
    queue<string> Q;
    Q.push("a");
    while (!Q.empty()) {
        auto v = Q.front(); Q.pop();
        if (v.length() == N) {
            ans++;
            continue;
        }
        int i = v[0] - 'a';
        for (auto p : inv[i]) {
            auto nv = p + v.substr(1);
            Q.push(nv);
        }
    }
    
    return ans;
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < Q; ++i) {
        string a, b;
        cin >> a >> b;
        ops[a] = b;
    }
    cout << solve() << endl;

    return 0;
}