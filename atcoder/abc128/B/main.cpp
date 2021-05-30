#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<tuple<string,int,int>> restraunts;

    cin >> N;
    restraunts.assign(N, make_tuple("", 0, 0));
    for (int i = 0; i < N; ++i) {
        string name; int score;
        cin >> name >> score;
        restraunts[i] = make_tuple(name, -score, i + 1);
    }
    sort(restraunts.begin(), restraunts.end());
    for (auto& restraunt : restraunts) {
        cout << get<2>(restraunt) << endl;
    }

    return 0;
}