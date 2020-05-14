// https://atcoder.jp/contests/abc159/tasks/abc159_a

#include <iostream>
#include <vector>

using namespace std;

int nC2(int n) {
    if (n == 1) return 0;
    return (n * (n-1) / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int ans = nC2(N) + nC2(M);
    cout << ans << endl;

    return 0;
}