#include <bits/stdc++.h>

using namespace std;

// O(N logN)
bool solve(const vector<int>& A, tuple<int,int,int>& triangle) {
    const int N = A.size();
    int k = N - 1;
    for (int i = 0; i < N; ++i) {
        int ub = A[k] - A[i];
        auto it = upper_bound(A.begin() + i + 1, A.end() - 1, ub);
        int j = distance(A.begin(), it) - 1;
        if (j > i && j < k) {
            triangle = make_tuple(i, j, k);
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    vector<int> A;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        A.assign(N, 0);
        for (int j = 0; j < N; ++j) {
            cin >> A[j];
        }
        tuple<int,int,int> triangle;
        auto ans = solve(A, triangle);
        if (ans) {
            cout << get<0>(triangle) + 1 << " "
                << get<1>(triangle) + 1 << " "
                << get<2>(triangle) + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}