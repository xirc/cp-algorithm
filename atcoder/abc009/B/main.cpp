#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;
    
    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    auto it = unique(A.begin(), A.end());
    A.erase(it, A.end());
    reverse(A.begin(), A.end());
    cout << A[1] << endl;

    return 0;
}