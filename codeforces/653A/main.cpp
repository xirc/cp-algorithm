// https://codeforces.com/contest/653/problem/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    
    bool ans = false;
    int M = A.size() - 2;
    for (int i = 0; i < M; ++i) {
        if (A[i+1] - A[i] == 1 && A[i+2] - A[i+1] == 1) {
            ans = true;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}