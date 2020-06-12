#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> WS;

// O(N)
int can_assign(int P) {
    int k = 0;
    int load = 0;
    for (int i = 0; i < N; ++i) {
        if (WS[i] > P) return false;
        if (WS[i] + load <= P) {
            load += WS[i];
        } else {
            if (k + 1 == K) {
                return false;
            } else {
                k++;
                load = WS[i];
            }
        }
    }
    return true;
}

// O(N logP)
int solve() {
    int minP = 1;
    int maxP = accumulate(WS.begin(), WS.end(), 0, plus<int>());
    while (maxP - minP > 0) {
        int midp = (minP + maxP) / 2;
        if (can_assign(midp)) {
            maxP = midp;
        } else {
            minP = midp + 1;
        }
    }
    return minP;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    WS.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> WS[i];
    }
    cout << solve() << endl;

    return 0;
}