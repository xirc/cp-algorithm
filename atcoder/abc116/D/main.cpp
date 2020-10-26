#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int K, N;
vector<int> T;
vector<int> D;

struct Table {
    ll _score;
    unordered_map<int,int> primary;
    multiset<pair<int,int>> secondary;
    Table() {
        _score = 0;
        primary = unordered_map<int,int>();
        secondary = multiset<pair<int,int>>();
    }
    void put(int type, int value) {
        _score += value;
        if (primary.count(type) == 0) {
            primary[type] = value;
        } else {
            secondary.insert({ value, type });
        }
    }
    bool has(int type) {
        return primary.count(type) > 0;
    }
    ll score() {
        return _score + ll(primary.size()) * primary.size();
    }
    int typeCount() {
        return primary.size();
    }
    bool canPop() {
        return !secondary.empty();
    }
    pair<int,int> pop() {
        auto it = secondary.begin();
        auto value = *it;
        _score -= value.first;
        secondary.erase(it);
        return value;
    }
};

ll solve() {
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = { D[i], T[i] };
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    Table table;
    set<int> availableTypes;
    priority_queue<pair<int,int>> available;
    for (int i = 0; i < K; ++i) {
        auto t = A[i].second, d = A[i].first;
        table.put(t, d);
    }
    for (int i = K; i < N; ++i) {
        auto t = A[i].second, d = A[i].first;
        if (!table.has(t) && availableTypes.count(t) == 0) {
            availableTypes.insert(t);
            available.push({ d, t });
        }
    }

    const int M = table.typeCount() + available.size();
    ll ans = table.score();
    while (table.typeCount() < M && table.canPop()) {
        table.pop();
        auto dt = available.top(); available.pop();
        auto t = dt.second, d = dt.first;
        table.put(t, d);
        ans = max(ans, table.score());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    T.assign(N, 0);
    D.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> D[i];
        --T[i];
    }
    cout << solve() << endl;

    return 0;
}