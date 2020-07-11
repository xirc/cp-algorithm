#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<pair<int,int>> A;
    
    cin >> N;
    A.assign(N, {0, 0});
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i) {
        cout << A[i].first << " " << A[i].second << endl;
    }

    return 0;
}