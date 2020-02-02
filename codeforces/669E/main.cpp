// http://codeforces.com/contest/669/problem/E

#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

class BIT {
    map<pair<int,int>,int> bit;
    int n;
public:
    BIT(int n): n(n+1), bit() {}
    // O (logN)
    int count(int x, int y) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += bit[{i,y}];
        }
        return ans;
    }
    // O (logN)
    void add(int x, int y, int value) {
        for (int i = x + 1; i < n; i += i & -i) {
            bit[{i,y}] += value;
        }
    }
};

int main() {
    int N;
    int a, t, x;
    BIT bit(1e9+1);

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &a, &t, &x);
        if (a == 1) {
            bit.add(t, x, 1);
        } else if (a == 2) {
            bit.add(t, x, -1);
        } else if (a == 3) {
            int ans = bit.count(t + 1, x);
            printf("%d\n", ans);
        }
    }

    return 0;
}