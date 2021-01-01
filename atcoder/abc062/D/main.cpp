#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    ll suml = 0;
    multiset<int, less<int>> best;
    ll sumr = 0;
    multiset<int, greater<int>> worst1;
    multiset<int, less<int>> worst2;

    for (int i = 0; i < N; ++i) {
        suml += A[i];
        best.insert(A[i]);
    }
    for (int i = N; i < 3 * N; ++i) {
        sumr += A[i];
        worst1.insert(A[i]);
        if (worst1.size() > N) {
            // pick max
            auto u = worst1.begin();
            sumr -= *u;
            worst2.insert(*u);
            worst1.erase(u);
        }
    }

    ll ans = suml - sumr;
    for (int i = N; i < 2 * N; ++i) {
        suml += A[i];
        best.insert(A[i]);
        // pick min
        auto u = best.begin();
        suml -= *u;
        best.erase(u);

        if (worst1.count(A[i]) > 0) {
            sumr -= A[i];
            worst1.erase(worst1.find(A[i]));
            // pick min
            auto v = worst2.begin();
            sumr += *v;
            worst1.insert(*v);
            worst2.erase(v);
        } else {
            assert(worst2.count(A[i]) > 0);
            worst2.erase(worst2.find(A[i]));
        }

        ans = max(ans, suml - sumr);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(3 * N, 0);
    for (int i = 0; i < 3 * N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}