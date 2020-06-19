#include <bits/stdc++.h>

using namespace std;

const int N = 45;
vector<int> fib(N);

void build_fib() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < N; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    build_fib();
    cout << fib[N] << endl;

    return 0;
}