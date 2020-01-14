// https://www.spoj.com/problems/GIVEAWAY/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 500000;
const int M = 1000;
const int S = 500;
int X[N];
int Y[M][S];

// O(MlogS+N)
void initialize() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < S; ++j) {
            int k = i * S + j;
            Y[i][j] = k < N ? X[k] : 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        sort(Y[i], Y[i]+S);
    }
}

// the number of elements in [l, r) greater than v
// O(sqrt(S)+sqrt(N)logS)
int query(int l, int r, int v) {
    int lb = l / S;
    int rb = r / S;

    if (lb == rb) {
        int ans = 0;
        for (int i = l; i < r; ++i) {
            if (X[i] > v) ++ans;
        }
        return ans;
    }

    int ans = 0;
    for (int i = l; i < lb * S + S; ++i) {
        if (X[i] > v) ++ans;
    }
    for (int i = rb * S; i < r; ++i) {
        if (X[i] > v) ++ans;
    }
    for (int b = lb + 1; b < rb; ++b) {
        auto it = upper_bound(Y[b], Y[b]+S, v);
        ans += Y[b]+S - it;
    }

    return ans;
}

// update the i-th element to v (0-base-index)
// O(logS+SlogS)
void update(int i, int v) {
    X[i] = v;
    int j = i / S;
    for (int k = 0; k < S; k++) {
        Y[j][k] = X[j * S + k];
    }
    sort(Y[j], Y[j]+S);
}

int main() {
    int n, q;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &X[i]);
    }

    initialize();

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t, a, b, c;
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d %d %d", &a, &b, &c);
            a--;
            b--;
            int ans = query(a, b + 1, c - 1);
            printf("%d\n", ans);
        } else if (t == 1) {
            scanf("%d %d", &a, &b);
            a--;
            update(a, b);
        }
    }
    
    return 0;
}