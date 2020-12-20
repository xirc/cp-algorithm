#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/algebra/binexp.hpp"

using namespace std;
using vec = vector<long long>;
using mat = vector<vec>;

mat id(int N) {
    mat ans(N, vec(N, 0));
    for (int i = 0; i < N; ++i) ans[i][i] = 1;
    return ans;
}

mat mul(const mat& lhs, const mat& rhs) {
    const int N = lhs.size(), M = rhs.size();
    mat ans(N, vec(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                ans[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return ans;
}

// O(logN)
mat binexp(const mat& a, int n) {
    return binexp<mat>(a, n, id(a.size()), mul);
}

// O(logN)
long long fib(int n) {
    if (n < 0) throw;
    if (n == 1 || n == 2) return 1;

    mat a = { { 0, 1 }, { 1, 1 } };
    mat f = binexp(a, n - 2);
    mat b = mul(f, mat { { 1 }, { 1 } });
    return b[1][0];
}

void action_eval() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "false" << endl;
        return;
    }
    auto ans = fib(n);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Fibonacci Number with binary exponentation";
    commands["eval"] =
        Command { "eval", action_eval };
}