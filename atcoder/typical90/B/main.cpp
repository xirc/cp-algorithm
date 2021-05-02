#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

map<int, vector<string>> cache;
vector<string> solve(int N) {
    if (N % 2 == 1) return {};
    if (N == 0) {
        return { "" };
    }
    if (cache.count(N)) {
        return cache[N];
    }

    vector<string> ans;
    for (auto const& s : solve(N-2)) {
        ans.push_back("()" + s);
        ans.push_back(s + "()");
        ans.push_back("(" + s + ")");
    }
    for (int i = 2; i < N; i += 2) {
        int j = N - i;
        auto ls = solve(i);
        auto rs = solve(j);
        for (auto const& lhs : ls) {
            for (auto const & rhs : rs) {
                ans.push_back(lhs + rhs);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return cache[N] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto ans = solve(N);
    for (auto const& p : ans) {
        cout << p << endl;
    }

    return 0;
}