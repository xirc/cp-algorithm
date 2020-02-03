// https://www.spoj.com/problems/SGIFT/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class BIT {
    vector<long long> bit;
    int n;
public:
    BIT(int n): n(n+1), bit(n+1) {}
    // sum of [0,x)
    long long sum(int x) {
        long long ans = 0;
        for (; x > 0; x -= x&-x) {
            ans += bit[x];
        }
        return ans;
    }
    //add v to array[x]
    void add(int x, int v) {
        for (x++; x < n; x += x&-x) {
            bit[x] += v;
        }
    }
};

int main() {
    int N, Q;

    scanf("%d", &N);

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &array[i]);
    }

    BIT bit(N);
    sort(array.begin(), array.end());
    for (int i = 0; i < N; ++i) {
        bit.add(i, array[i]);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int l = distance(array.begin(), lower_bound(array.begin(), array.end(), a));
        int r = distance(array.begin(), upper_bound(array.begin(), array.end(), b));
        long long ans = bit.sum(r) - bit.sum(l);
        printf("%lld\n", ans);
    }

    return 0;
}