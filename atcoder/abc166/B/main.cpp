#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> B(N, 0);
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d;
        for (int j = 0; j < d; ++j) {
            int a;
            cin >> a;
            B[a-1]++;
        }
    }

    int ans = count_if(B.begin(), B.end(), [](int b) { return b == 0; });
    cout << ans << endl;

    return 0;
}