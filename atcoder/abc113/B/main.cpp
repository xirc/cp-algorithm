#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, T, A;
    vector<int> H;
    vector<int> S;

    cin >> N >> T >> A;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    for (int i = 0; i < N; ++i) {
        H[i] = T * 1000 - H[i] * 6;
        H[i] = abs(A * 1000 - H[i]);
    }
    int index = distance(H.begin(), min_element(H.begin(), H.end()));
    cout << (index + 1) << endl;

    return 0;
}