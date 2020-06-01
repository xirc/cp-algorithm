#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    while (cin >> N, N > 0) {
        vector<int> S(N);
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }

        double mean = accumulate(S.begin(), S.end(), 0, plus<int>()) / (double)N;
        double variance = 0;
        for (int i = 0; i < N; ++i) {
            variance += (S[i] - mean) * (S[i] - mean);
        }
        variance /= N;
        double stddev = sqrt(variance);
        cout << fixed << setprecision(4) << stddev << endl;
    }
    return 0;
}