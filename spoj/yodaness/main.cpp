// https://www.spoj.com/problems/YODANESS/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n): n(n+1), bit(n+1) {}
    int sum(int l, int r) {
        return sum(r) - sum(l);
    }
    int sum(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += bit[x];
        }
        return ans;
    }
    void add(int x, int value) {
        for (++x; x < n; x += x & -x) {
            bit[x] += value;
        }
    }
};

long long solve(int n, vector<string>& yoda, vector<string>& norm) {
    const int M = 30000;
    long long ans = 0;
    BIT bit(M);
    map<string,int> index_by_word;

    for (int i = 0; i < norm.size(); ++i) {
        index_by_word[norm[i]] = i;
    }
    for (int i = 0; i < yoda.size(); ++i) {
        int index = index_by_word[yoda[i]];
        ans += bit.sum(index, M);
        bit.add(index, 1);
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        vector<string> yoda(N);
        vector<string> norm(N);
        for (int j = 0; j < N; ++j) {
            cin >> yoda[j];
        }
        for (int j = 0; j < N; ++j) {
            cin >> norm[j];
        }
        long long ans = solve(N, yoda, norm);
        cout << ans << endl;
    }

    return 0;
}