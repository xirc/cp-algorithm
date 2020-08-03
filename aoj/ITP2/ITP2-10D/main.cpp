#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bitset<64> value;
    vector<bitset<64>> mask;

    int N;
    cin >> N;
    mask.assign(N, bitset<64>());
    for (int i = 0; i < N; ++i) {
        int K, b;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> b;
            mask[i][b] = true;
        }
    }

    int Q;
    cin >> Q;
    int t, m;
    for (int i = 0; i < Q; ++i) {
        cin >> t >> m;
        if (t == 0) {
            // test i-th flag is ON
            auto ans = value[m] ? 1 : 0;
            cout << ans << endl;
        } else if (t == 1) {
            // set flags specified by mask m
            value |= mask[m];
        } else if (t == 2) {
            // clear flags specified by mask m
            value &= ~mask[m];
        } else if (t == 3) {
            // inverse flags specified by mask m
            value ^= mask[m];
        } else if (t == 4) {
            // test all flags specified by mask m are ON
            auto v = value | ~mask[m];
            auto ans = v.all() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 5) {
            // test at least one flag specified by mask m is ON
            auto v = value & mask[m];
            auto ans = v.any() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 6) {
            // test all flags specified by mask m is OFF
            auto v = value & mask[m];
            auto ans = v.none() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 7) {
            // count the number of flags specified by mask m with ON
            auto v = value & mask[m];
            auto ans = v.count();
            cout << ans << endl;
        } else if (t == 8) {
            // get the decimal value of the state specified by mask m
            auto v = value & mask[m];
            auto ans = v.to_ulong();
            cout << ans << endl;
        } else throw;
    }

    return 0;
}