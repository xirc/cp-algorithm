#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    map<string,int> votes;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        votes[s]++;
    }

    int maxi = 0;
    string top;
    for (auto const& e : votes) {
        if (e.second > maxi) {
            maxi = e.second;
            top = e.first;
        }
    }
    cout << top << endl;

    return 0;
}