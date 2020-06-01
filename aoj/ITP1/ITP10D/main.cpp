#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> y[i];
    }

    vector<double> d(N);
    for (int i = 0; i < N; ++i) {
        d[i] = abs(x[i] - y[i]);
    }

    double d1 = 0;
    double d2 = 0;
    double d3 = 0;
    double dc = 0;
    for (int i = 0; i < N; ++i) {
        d1 += d[i];
        d2 += d[i] * d[i];
        d3 += d[i] * d[i] * d[i];
        dc = max(dc, d[i]);
    }
    d2 = sqrt(d2);
    d3 = cbrt(d3);

    cout << fixed << setprecision(5);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << dc << endl;

    return 0;
}