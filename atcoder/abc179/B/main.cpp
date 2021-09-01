#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    bool exists_3consecutive = false;
    int consecutive_doublets = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        bool is_doublets = a == b;
        if (is_doublets) {
            ++consecutive_doublets;
        } else {
            consecutive_doublets = 0;
        }
        if (consecutive_doublets == 3) {
            exists_3consecutive = true;
        }
    }
    cout << (exists_3consecutive ? "Yes" : "No") << endl;

    return 0;
}