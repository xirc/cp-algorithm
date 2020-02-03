// http://codeforces.com/contest/777/problem/E

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class BIT {
    map<int,long long> bit;
    const int n = 1e9 + 100;
public:
    // max of array[0,index)
    long long max(int index) {
        long long ans = 0;
        for (; index > 0; index -= index & -index) {
            ans = std::max(ans, bit[index]);
        }
        return ans;
    }
    // update array[index] = max(array[index],value)
    void update(int index, long long value) {
        for (index++; index < n; index += index & -index) {
            bit[index] = std::max(bit[index], value);
        }
    }
};

struct Ring {
    int inner, outer, height;
    static bool greater(const Ring& lhs, const Ring& rhs) {
        return lhs.outer == rhs.outer ? (lhs.inner > rhs.inner) : (lhs.outer > rhs.outer);
    }
};

long long solve(vector<Ring>& rings) {
    BIT bit;
    
    sort(rings.begin(), rings.end(), Ring::greater);

    long long ans = 0;
    for (auto ring : rings) {
        long long value = bit.max(ring.outer) + ring.height;
        bit.update(ring.inner, value);
        ans = max(ans, value);
    }

    return ans;
}

int main() {
    int N, a, b, h;
    
    scanf("%d", &N);
    vector<Ring> rings(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &a, &b, &h);
        rings[i] = Ring { a, b, h };
    }

    long long ans = solve(rings);
    printf("%lld\n", ans);

    return 0;
}