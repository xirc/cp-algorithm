#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    string s;

    map<string,int> netp;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        netp[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> s;
        netp[s]--;
    }

    int maxp = 0;
    for (auto const& e : netp) {
        maxp = max(maxp, e.second);
    }
    cout << maxp << endl;

    return 0;
}