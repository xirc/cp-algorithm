#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

vector<int> divisors(int M) {
    vector<int> r;
    for (int i = 1; i * i <= M; ++i) {
        if (M % i != 0) continue;
        r.push_back(i);
        if (M / i != i) r.push_back(M / i);
    }
    return r;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int N;
vector<int> A;

int solve() {
    int const L = *min_element(A.begin(), A.end());
    map<int,int> mp;
    for (auto a : A) {
        auto ds = divisors(a);
        for (auto v : ds) {
            if (v > L) continue;
            if (mp.count(v)) {
                mp[v] = gcd(mp[v],a);
            } else {
                mp[v] = a;
            }
        }
    }
    int ans = 0;
    for (auto const& e : mp) {
        int v, a;
        tie(v, a) = e;
        if (v == a) ++ans;
    }
    return ans;
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