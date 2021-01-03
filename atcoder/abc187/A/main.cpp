#include <bits/stdc++.h>

using namespace std;

int S(int N) {
    int s = 0;
    while (N > 0) {
        s += N % 10;
        N /= 10;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    int sa = S(A), sb = S(B);
    if (sa >= sb) {
        cout << sa << endl;
    } else {
        cout << sb << endl;
    }

    return 0;
}