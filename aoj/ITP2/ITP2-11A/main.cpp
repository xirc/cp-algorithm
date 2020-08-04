#include <bits/stdc++.h>

using namespace std;

void dump(int S) {
    cout << S << ":";
    int i = 0;
    while (S > 0) {
        if (S & 1) {
            cout << " " << i;
        }
        S >>= 1;
        i++;
    }
    cout << endl;
}

// 0,1,2,3,4,5,6,...,17,18
// O(2^N)
// N=18: 2^18 = 1024 * 256 = 256 K
void solve(int N) {
    assert(N >= 1 && N <= 18);
    int M = 1 << N;
    for (int s = 0; s < M; ++s) {
        dump(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    solve(N);

    return 0;
}