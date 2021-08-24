#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string,int> count;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        count[S]++;
    }

    vector<string> cases = { "AC", "WA", "TLE", "RE" };
    for (auto cs : cases) {
        cout << cs << " x " << count[cs] << endl;
    }

    return 0;
}