// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> A;

int solve() {
    int r = 0;
    int ans = N + 1;
    int sum = 0;
    for (int l = 0; l < N; l++) {
        while (r < l) r++;
        while (r < N && sum < S) {
            sum += A[r];
            r++;
        }

        if (sum >= S) {
            ans = min(ans, r - l);
        }

        sum -= A[l];
    }
    
    if (ans == N + 1) {
        return 0;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}