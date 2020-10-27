#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> P;

    cin >> N;
    P.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int maxi = *max_element(P.begin(), P.end());
    int sum = accumulate(P.begin(), P.end(), 0, plus<int>());
    sum -= maxi;
    sum += maxi / 2;
    cout << sum << endl;

    return 0;
}