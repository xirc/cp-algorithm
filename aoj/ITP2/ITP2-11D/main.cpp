#include <bits/stdc++.h>

using namespace std;

void dump(int S) {
    cout << S << ":";
    int i = 0;
    while (S > 0) {
        if (S & 1) {
            cout << " " << i;
        }
        i++;
        S >>= 1;
    }
    cout << endl;
}

void solve(const int N, const int K) {
    int M = 1 << N;
    for (int i = 0; i < M; ++i) {
        if (bitset<32>(i).count() == K) {
            dump(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    solve(N, K);

    return 0;
}