#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> A;

vector<int> divisors(int M) {
    set<int> ds;
    for (int i = 1; i * i <= M; ++i) {
        if (M % i == 0) {
            ds.insert(i);
            ds.insert(M / i);
        }
    }
    return vector<int>(ds.begin(), ds.end());
}

bool pass(int X) {
    vector<int> B(N, 0);
    for (int i = 0; i < N; ++i) {
        B[i] = A[i] % X;
    }
    int sum = accumulate(B.begin(), B.end(), 0, plus<int>());
    if (sum % X != 0) {
        return false;
    }
    sort(B.begin(), B.end());
    int count = 0;
    int l = 0, r = N-1;
    while (l < r) {
        if (B[l] == 0) {
            ++l;
            continue;
        }
        if (B[r] == X) {
            --r;
            continue;
        }
        int o = min(B[l], X - B[r]);
        B[l] -= o;
        B[r] += o;
        count += o;
    }
    return count <= K;
}

int solve() {
    int S = accumulate(A.begin(), A.end(), 0, plus<int>());
    auto xs = divisors(S);
    reverse(xs.begin(), xs.end());
    for (auto x : xs) {
        if (pass(x)) return x;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}