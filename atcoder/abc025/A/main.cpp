#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    int N;

    cin >> S >> N;
    --N;
    int i = (N / 5) % 5;
    int j = (N % 5);
    cout << S[i] << S[j] << endl;

    return 0;
}