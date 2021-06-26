#include <bits/stdc++.h>

inline std::vector<size_t> zalgorithm(std::string const& S) {
    size_t const N = S.size();
    std::vector<size_t> Z(N, 0);
    size_t L, R;
    L = R = 0;
    auto const extend_and_update = [&](int i) {
        while (R < N && S[R-L] == S[R]) ++R;
        Z[i] = R - L;
        --R;
    };
    for (size_t i = 0; i < N; ++i) {
        auto K = i - L;
        auto len = R - i + 1;
        if (i <= R && Z[K] < len) {
            Z[i] = Z[K];
        } else {
            if (i > R) L = R = i;
            else L = i;
            extend_and_update(i);
        }
    }
    return Z;
}


using namespace std;
using ll = int64_t;
using ff = long double;

// O(N**2)
int solve(int N, string const& S) {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        auto T = S.substr(i);
        auto zs = zalgorithm(T);
        for (int j = 1; j < T.size(); ++j) {
            int l1 = j;
            int z = zs[j];
            ans = max(ans, min(l1, z));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    cout << solve(N, S) << endl;

    return 0;
}