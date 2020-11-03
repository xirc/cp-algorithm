#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> V;

int solve() {
    assert(N % 2 == 0);
    const int M = N / 2;
    unordered_map<int,int> A, B;

    for (int i = 0; i < N; ++i) {
        if (i & 1) {
            ++A[V[i]];
        } else {
            ++B[V[i]];
        }
    }

    vector<pair<int,int>> aa;
    vector<pair<int,int>> bb;
    for (auto e : A) {
        aa.push_back({ e.second, e.first });
    }
    for (auto e : B) {
        bb.push_back({ e.second, e.first });
    }
    sort(aa.begin(), aa.end());
    reverse(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    reverse(bb.begin(), bb.end());
    
    if (aa[0].second != bb[0].second) {
        return (M - aa[0].first) + (M - bb[0].first);
    }
    if (M == 1) {
        int maxi = max(aa[0].first, bb[0].first);
        return (M - maxi) + M;
    }
    int semi = max(aa[1].first, bb[1].first);
    return (M - aa[0].first) + (M - semi);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    V.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    cout << solve() << endl;

    return 0;
}