#include <bits/stdc++.h>

using namespace std;

bool solve(int A, int B, int C, int D) {
    int total = A + B + C + D;
    for (int s = 0; s < 16; ++s) {
        int use = 0;
        if ((s >> 3) & 1) use += A;
        if ((s >> 2) & 1) use += B;
        if ((s >> 1) & 1) use += C;
        if ((s >> 0) & 1) use += D;
        if (use == total - use) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    auto ans = solve(A, B, C, D) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}