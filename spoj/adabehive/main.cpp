// https://www.spoj.com/problems/ADABEHIVE/

#include <cstdio>
#include <vector>

using namespace std;

class BIT {
    vector<vector<long long>> bit;
    int n, m;

public:
    BIT(int n, int m): n(n+1), m(m+1), bit(n+1,vector<long long>(m+1)) {}
    long long sum(int xl, int yl, int xr, int yr) {
        long long ans = 0;
        ans += sum(xr, yr);
        ans -= sum(xl, yr);
        ans -= sum(xr, yl);
        ans += sum(xl, yl);
        return ans;
    }
    long long sum(int x, int y) {
        long long ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans += bit[i][j];
            }
        }
        return ans;
    }
    void add(int x, int y, int value) {
        for (int i = x + 1; i < n; i += i & -i) {
            for (int j = y + 1; j < m; j += j & -j) {
                bit[i][j] += value;
            }
        }
    }
};

int main() {
    int N, M, Q;

    scanf("%d %d %d", &N, &M, &Q);

    BIT bit(N, M);

    int value;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &value);
            bit.add(i, j, value);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            int i, j, p;
            scanf("%d %d %d", &i, &j, &p);
            --i, --j;
            bit.add(i, j, p);
        } else if (k == 2) {
            int i1, j1, i2, j2;
            scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
            --i1, --j1, --i2, --j2;
            long long ans = bit.sum(i1, j1, i2 + 1, j2 + 1);
            printf("%lld\n", ans);
        }
    }

    return 0;
}