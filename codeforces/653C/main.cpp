// https://codeforces.com/contest/653/problem/C

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

inline bool is_nice(int idx) {
    if (idx < 0 || idx >= N) return true;
    bool ans = true;
    if (idx % 2 == 1) {
        ans &= idx + 1 < N ? A[idx] > A[idx+1] : true;
        ans &= idx - 1 >= 0 ? A[idx] > A[idx-1] : true;
    } else {
        ans &= idx + 1 < N ? A[idx] < A[idx+1] : true;
        ans &= idx - 1 >= 0 ? A[idx] < A[idx-1] : true;
    }
    return ans;
}

void dump() {
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int solve() {
    set<int> indice;
    set<pair<int,int>> ans;

    for (int i = 0; i < N; ++i) {
        if (!is_nice(i)) {
            indice.insert(i);
        }
    }

    // the sequence cannot be nice.
    if (indice.size() > 6) {
        return 0;
    }

    for (auto u : indice) {
        for (int i = 0; i < N; ++i) {
            if (i == u) continue;
            swap(A[u], A[i]);
            bool nice = true;
            nice &= is_nice(u-1) && is_nice(u) && is_nice(u+1);
            nice &= is_nice(i-1) && is_nice(i) && is_nice(i+1);
            for (auto v : indice) nice &= is_nice(v);
            if (nice) ans.insert({min(i,u),max(i,u)});
            swap(A[u], A[i]);
        }
    }

    return ans.size();
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