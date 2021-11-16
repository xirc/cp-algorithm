#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> C;
    cin >> N >> K;
    C.assign(N, 0);
    for (auto &c : C) cin >> c;

    unordered_map<int,int> count;

    for (int i = 0; i < K; ++i) {
        count[C[i]]++;
    }
    int ans = count.size();

    for (int i = K; i < N; ++i) {
        count[C[i-K]]--;
        count[C[i]]++;
        if (count[C[i-K]] == 0) count.erase(C[i-K]);
        ans = max(ans, (int)count.size());
    }
    cout << ans << endl;

    return 0;
}