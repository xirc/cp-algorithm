// https://www.spoj.com/problems/INVCNT/

// Case 1
// 3
// 3 1 -> 1 3 (+1
// 1 3 2 -> 1 2 3 (+1

// Case 2
// 2
// 2 3
// 2 3 8
// 2 3 8 6 -> 2 3 6 8 (+1)
// 2 3 6 8 1 -> 1 2 3 6 8 (+4)

#include <cstdio>
#include <vector>

using namespace std;

class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n): n(n+1), bit(n+1) {}
    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }
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
        for (x++; x < n; x += x & -x) {
            bit[x] += value;
        }
    }
};

const int MAX_M = 1e7;
BIT bit(MAX_M + 1);
long long solve(vector<int>& array) {
    long long ans = 0;

    bit.clear();
    for (int i = 0; i < array.size(); ++i) {
        ans += bit.sum(array[i], MAX_M + 1);
        bit.add(array[i], 1);
    }

    return ans;
}

int main()
{
    int T, N;

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &N);
        vector<int> array(N);
        for (int j = 0; j < N; ++j) {
            scanf("%d", &array[j]);
        }
        long long ans = solve(array);
        printf("%lld\n", ans);
    }

    return 0;
}