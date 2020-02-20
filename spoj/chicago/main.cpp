// https://www.spoj.com/problems/CHICAGO/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int N, M;
vector<vector<double>> Pr;

double solve() {
    const double EPS = 1e-8;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                double np = Pr[i][k] * Pr[k][j];
                if (np > Pr[i][j] - EPS) {
                    Pr[i][j] = np;
                }
            }
        }
    }
    return Pr[0][N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        cin >> N;
        if (N == 0) break;
        Pr.assign(N, vector<double>(N, 0));
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int a, b, p;
            cin >> a >> b >> p;
            --a, --b;
            Pr[a][b] = p / 100.0;
            Pr[b][a] = p / 100.0;
        }
        cout << fixed << setprecision(6) << solve() * 100 << " percent" << endl;
    }

    return 0;
}