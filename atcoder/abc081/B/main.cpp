#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

int solve() {
    int count = 32;
    for (auto v : A) {
        int c = 0;
        while (v % 2 == 0) {
            v /= 2;
            ++c;
        }
        count = min(count, c);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}