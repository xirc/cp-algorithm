#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<array<int,3>> is;

int solve() {
    vector<int> A(M + 1, 0), B(M + 1, 0);

    {
        sort(is.begin(), is.end(), [&](auto const& lhs, auto const& rhs) {
            return lhs[1] < rhs[1];
        });
        auto it = is.begin();
        for (int i = 1; i < M + 1; ++i) {
            A[i] = A[i-1];
            while (it != is.end() && (*it)[1] < i) {
                A[i] += (*it)[2];
                ++it;
            }
        }
    }
    
    {
        sort(is.begin(), is.end(), [&](auto const& lhs, auto const& rhs) {
            return lhs[0] > rhs[0];
        });
        auto it = is.begin();
        for (int i = M - 1; i >= 0; --i) {
            B[i] = B[i+1];
            while (it != is.end() && (*it)[0] >= i) {
                B[i] += (*it)[2];
                ++it;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < M; ++x) {
        ans = max(ans, A[x] + B[x+1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    is.assign(N, array<int,3>());
    for (int i = 0; i < N; ++i) {
        cin >> is[i][0]
            >> is[i][1]
            >> is[i][2];
        --is[i][0]; --is[i][1];
    }
    cout << solve() << endl;

    return 0;
}