#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, T;
vector<int> A;

int solve() {
    vector<int> DPmax(N, 0);
    vector<int> DPcount(N, 0);
    DPmax[N-1] = A[N-1];
    DPcount[N-1] = 1;
    for (int i = N - 2; i >= 0; --i) {
        DPmax[i] = max(A[i], DPmax[i+1]);
        DPcount[i] = DPcount[i+1];
        if (A[i] == DPmax[i+1]) {
            DPcount[i] += 1;
        } else if (A[i] > DPmax[i+1]) {
            DPcount[i] = 1;
        }
    }

    vector<int> is;
    ll max_prof = 0;
    for (int i = N - 2; i >= 0; --i) {
        ll prof = max(DPmax[i+1] - A[i], 0) * (ll(T) / 2);
        if (prof > max_prof) {
            is.clear();
            is.push_back(i);
            max_prof = prof;
        } else if (prof == max_prof) {
            is.push_back(i);
        }
    }
    assert((int)is.size() > 0);

    int ans = 0;
    for (auto i : is) {
        ans += DPcount[i+1];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}