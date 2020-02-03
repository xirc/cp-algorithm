// https://www.spoj.com/problems/TULIPNUM/

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n): n(n+1), bit(n+1) {}
    int sum(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += bit[x];
        }
        return ans;
    }
    void add(int x, int v) {
        for (x++; x < n; x += x & -x) {
            bit[x] += v;
        }
    }
};

int main() {
    int T, N, Q;

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d", &N, &Q);

        vector<int> array(N);

        for (int i = 0; i < N; ++i) {
            scanf("%d", &array[i]);
        }

        BIT bit(N);
        
        bit.add(0, 1);
        for (int i = 1; i < N; ++i) {
            if (array[i] > array[i-1]) bit.add(i, 1);
        }

        printf("Case %d:\n", t+1);
        for (int q = 0; q < Q; q++) {
            int i, j;
            scanf("%d %d", &i, &j);
            --i, --j;
            i = distance(array.begin(), lower_bound(array.begin(), array.end(), array[i]));
            int ans = bit.sum(j+1) - bit.sum(i);
            printf("%d\n", ans);
        }
    }

    return 0;
}