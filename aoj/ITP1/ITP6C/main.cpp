#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    array<array<array<int,10>,3>,4> A = { 0 };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int b, f, r, v;
        cin >> b >> f >> r >> v;
        --b, --f, --r;
        A[b][f][r] += v;
    }

    string s(20, '#');
    for (int b = 0; b < A.size(); ++b) {
        if (b > 0) cout << s << endl;
        for (int f = 0; f < A[b].size(); ++f) {
            for (int r = 0; r < A[b][f].size(); ++r) {
                cout << " " << A[b][f][r];
            }
            cout << endl;
        }
    }

    return 0;
}