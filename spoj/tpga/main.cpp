// https://www.spoj.com/problems/TPGA/

/*

1 2 3
-
1 2 3 | 2*0 + 1*0 + 0
1 3 2 | 2*0 + 1*1 + 0
2 1 3 | 2*1 + 1*0 + 0
2 3 1 | 2*1 + 1*1 + 0
3 1 2 | 2*2 + 1*0 + 0
3 2 1 | 2*2 + 1*1 + 0

1 2 3 4
-
1 2 3 4 | 6*0 + 2*0 + 1*0 + 0
1 2 4 3 | 6*0 + 2*0 + 1*1 + 0
1 3 2 4 | ...
1 3 4 2 | 
1 4 2 3 | 
1 4 3 2 | 

1 2 3 4
-
2 1 3 4 | 1 / 6*1 + 0 + 0 + 0
2 1 4 3 | 2 / 6*1 + 0 + 1 + 0
2 3 1 4 | 2 / 6*1 + 2*1 + 0 + 0
2 3 4 1 | 3 / 6*1 + 2*1 + 1 + 0
2 4 1 3 | 3 / 6*1 + 2*2 + 0 + 0
2 4 3 1 | 4 / 6*1 + 2*2 + 1 + 0
*/

#include <cstdio>
#include <vector>

using namespace std;

class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n): n(n+1), bit(n+1) {}
    int sum(int x) {
        int ans = 0;
        for (; x > 0; x -= x&-x) {
            ans += bit[x];
        }
        return ans;
    }
    void add(int x, int v) {
        for (x++; x < n; x += x&-x) {
            bit[x] += v;
        }
    }
};

const int MOD = 1000000007;
vector<long long> com(200001);
void init_com() {
    com[0] = 0;
    com[1] = 1;
    for (int i = 2; i < com.size(); ++i) {
        com[i] = (i * com[i-1]) % MOD;
    }
}

long long perm_rank(vector<int>& perm) {
    const int N = perm.size();
    BIT bit(N+1);
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        int index = N - 1 - i;
        int count = bit.sum(perm[index]);
        bit.add(perm[index], 1);
        ans += count * com[i];
    }
    return (ans + 1) % MOD;
}

int main() {
    int T, N;

    init_com();

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &N);
        vector<int> perm(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &perm[i]);
        }
        long long ans = perm_rank(perm);
        printf("%lld\n", ans);
    }

    return 0;
}