#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve(int sign) {
    assert(sign == 1 || sign == -1);
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        int c1 = (sign == 1 && sum <= 0) ? -sum + 1 : 0;
        int c2 = (sign == -1 && sum >= 0) ? sum + 1 : 0;
        assert(c1 >= 0 && c2 >= 0);
        sum += c1 + -c2;
        sign *= -1;
        ans += c1 + c2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << min(solve(1), solve(-1)) << endl;

    return 0;
}