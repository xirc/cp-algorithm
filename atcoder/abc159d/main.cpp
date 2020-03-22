// https://atcoder.jp/contests/abc159/tasks/abc159_d

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;

long long nC2(int n) {
    if (n <= 1) return 0;
    return (long long)n * (n-1) / 2;
}

void solve() {
    long long all = 0;
    vector<int> count(N + 1, 0);
    for (int i = 0; i < A.size(); ++i) {
        count[A[i]]++;
    }
    for (int i = 0; i < count.size(); ++i) {
        all += nC2(count[i]);
    }
    for (int i = 0; i < A.size(); ++i) {
        long long diff = nC2(count[A[i]]) - nC2(count[A[i]] - 1);
        cout << all - diff << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    solve();

    return 0;
}