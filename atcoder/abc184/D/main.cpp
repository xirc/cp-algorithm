#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int const N = 101;
int A, B, C;
vector<vector<vector<bool>>> cached(N, vector<vector<bool>>(N, vector<bool>(N, false)));
vector<vector<vector<ff>>> probability(N, vector<vector<ff>>(N, vector<ff>(N, 0)));
ff prob(int a, int b, int c) {
    if (a == A && b == B && c == C) return 1;
    if (cached[a][b][c]) {
        return probability[a][b][c];
    }
    ff p = 0;
    ff m = ff(a + b + c - 1);
    if (a > A && b != 100 && c != 100) {
        p += prob(a-1, b, c) * (a - 1) / m;
    }
    if (a != 100 && b > B && c != 100) {
        p += prob(a, b-1, c) * (b - 1) / m;
    }
    if (a != 100 && b != 100 && c > C) {
        p += prob(a, b, c-1) * (c - 1) / m;
    }
    cached[a][b][c] = true;
    probability[a][b][c] = p;
    return probability[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;
    ff ep = 0;
    for (int a = A; a <= 100; ++a) {
        for (int b = B; b <= 100; ++b) {
            for (int c = C; c <= 100; ++c) {
                if (a != 100 && b != 100 && c != 100) continue;
                if (a == 100 && b == 100) continue;
                if (b == 100 && c == 100) continue;
                if (c == 100 && a == 100) continue;
                int x = (a + b + c - A - B - C);
                ff p = prob(a, b, c);
                ep += x * p;
            }
        }
    }
    cout << fixed << setprecision(7) << ep << endl;

    return 0;
}