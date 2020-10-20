#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector<int> acc;

void build() {
    acc.assign(N, 0);
    for (int i = 0; i + 1 < N; ++i) {
        if (S[i] == 'A' && S[i+1] == 'C') {
            ++acc[i];
        }
    }
    for (int i = 1; i < N; ++i) {
        acc[i] += acc[i-1];
    }
}
// [l,r]
int query(int l, int r) {
    assert(l >= 0 && l < r && r < N);
    int ans = acc[r-1];
    if (l - 1 >= 0) {
        ans -= acc[l-1];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    int l, r;

    cin >> N >> Q;
    cin >> S;

    build();

    for (int i = 0; i < Q; ++i) {
        cin >> l >> r;
        --l; --r;
        cout << query(l, r) << endl;
    }

    return 0;
}