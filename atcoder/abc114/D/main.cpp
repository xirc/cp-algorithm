#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
    unordered_map<int,int> factors;
    for (int i = 2; i <= N; ++i) {
        int v = i;
        for (int j = 2; j <= i; ++j) {
            while (v % j == 0) {
                ++factors[j];
                v /= j;
            }
        }
    }

    vector<int> Z;
    for (auto e : factors) {
        Z.push_back(e.second + 1);
    }
    sort(Z.begin(), Z.end());
    int o75 = distance(lower_bound(Z.begin(), Z.end(), 75), Z.end());
    int o25 = distance(lower_bound(Z.begin(), Z.end(), 25), Z.end());
    int o15 = distance(lower_bound(Z.begin(), Z.end(), 15), Z.end());
    int o5 = distance(lower_bound(Z.begin(), Z.end(), 5), Z.end());
    int o3 = distance(lower_bound(Z.begin(), Z.end(), 3), Z.end());

    int ans = o75
        + o25 * (o3 - 1)
        + o15 * (o5 - 1)
        + o5 * (o5 - 1) * (o3 - 2) / 2;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}