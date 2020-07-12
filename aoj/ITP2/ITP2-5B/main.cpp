#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<tuple<int,int,char,long long,string>> A;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int v, w;
        char t;
        long long d;
        string s;
        cin >> v >> w >> t >> d >> s;
        A.push_back(make_tuple(v, w, t, d, s));
    }

    sort(A.begin(), A.end());
    for (auto e : A) {
        cout
            << get<0>(e) << " "
            << get<1>(e) << " "
            << get<2>(e) << " "
            << get<3>(e) << " "
            << get<4>(e) << endl;
    }

    return 0;
}