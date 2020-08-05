#include <bits/stdc++.h>

using namespace std;

void dump(int S) {
    int i = 0;
    cout << S << ":";
    while (S > 0) {
        if (S & 1) {
            cout << " " << i;
        }
        S >>= 1;
        i++;
    }
    cout << endl;
}

int parse(const vector<int>& bs) {
    bitset<20> bits(0);
    for (auto b : bs) {
        bits[b] = true;
    }
    return bits.to_ulong();
}

void solve(const int N, const vector<int>& bs) {
    const int M = 1 << N;
    const int T = parse(bs);
    for (int U = 0; U < M; ++U) {
        if ((U & T) == T) {
            dump(U);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> bs;
    cin >> N >> K;
    bs.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> bs[i];
    }
    solve(N, bs);

    return 0;
}