// https://www.spoj.com/problems/LASTDIG/

#include <iostream>

using namespace std;

int pow(int b, int e, int m) {
    b %= m;
    int res = 1;
    while (e) {
        if (e & 1) {
            res = res * b % m;
        }
        b = b * b % m;
        e >>= 1;
    }
    return res;
}

int main() {
    int T, A, B;
    
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        cout << pow(A, B, 10) << endl;
    }

    return 0;
}