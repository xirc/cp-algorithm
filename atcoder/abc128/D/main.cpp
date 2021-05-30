#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> vs;

int solve(int M) {
    int ans = 0;
    for (int l = 0; l <= min(N, K - M); ++l) {
        int r = min(N, K - M) - l;
        vector<int> xs;
        for (int i = 0; i < l; ++i) {
            xs.push_back(vs[i]);
        }
        for (int i = 0; i < r; ++i) {
            xs.push_back(vs[N-1-i]);
        }
        sort(xs.begin(), xs.end());
        reverse(xs.begin(), xs.end());
        for (int i = 0; i < M && !xs.empty(); ++i) {
            if (xs[xs.size()-1] > 0) break;
            xs.pop_back();
        }
        int sum = accumulate(xs.begin(), xs.end(), 0, plus<int>());
        ans = max(ans, sum);
    }
    return ans;
}

int solve() {
    int ans = 0;
    for (int m = 0; 2 * m < K; ++m) {
        ans = max(ans, solve(m));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    vs.assign(N, 0);
    for (auto& v : vs) cin >> v;
    cout << solve() << endl;

    return 0;
}