// https://www.spoj.com/problems/CTRICK/

#include <cstdio>
#include <vector>

using namespace std;

class BinaryIndexedTree {
    int N;
    // 1-index-base
    vector<int> table;

public:
    BinaryIndexedTree(int n) {
        N = n + 1;
        table = vector<int>(N, 0);
    }

    // O(N)
    inline void clear() {
        fill(table.begin(), table.end(), 0);
    }

    // add v to table[x]
    // O(logN)
    inline void add(int x, int v) {
        x++;
        if (x <= 0) return;
        for (; x < N; x += x&-x) {
            table[x] += v;
        }
    }

    // the sum of table [0,x)
    // O(logN)
    inline int sum(int x) {
        if (x <= 0) return 0;
        int v = 0;
        for (; x > 0; x -= x&-x) {
            v += table[x];
        }
        return v;
    }

    // the sum of table [l,r)
    // O(1)
    inline int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // search mininum index if the sum of table [0,index] == x
    // O(logN)
    int search(int x, int l, int yl, int yr) {
        // culling
        if (yr <= yl || sum(l, yr) < x) {
            return -1;
        }
        if (yr - yl == 1) {
            return sum(l, yr) == x ? yl : -1;
        }
        int m = (yl + yr) / 2;
        int ans = search(x, l, yl, m);
        if (ans != -1) {
            return ans;
        }
        return search(x, l, m, yr);
    }
};

// O (N logN)
void solve(BinaryIndexedTree& tree, vector<int>& ans, int n)
{
    // clear
    tree.clear();
    for (int i = 0; i <= n; ++i) {
        tree.add(i, 1);
        ans[i] = 0;
    }

    // solve
    int l = 0;
    for (int i = 0; i < n; ++i) {
        int x = i + 1 + 1;
        int sln = tree.sum(l, n);
        if (x > sln) {
            x -= sln;
            int s = n - i; // == tree.sum(n);
            x %= s;
            if (x == 0) x += s;
            l = 0;
        }
        int index = tree.search(x, l, l, n);
        ans[index] = i + 1;
        l = (index + 1) % n;
        tree.add(index, -1);
    }
}

int main() {
    const int MAX_N = 20000;
    BinaryIndexedTree bit(MAX_N);
    vector<int> ans(MAX_N);

    int Q, N;
    scanf("%d", &Q);

    for (int i = 0; i < Q; ++i) {
        scanf("%d", &N);
        solve(bit, ans, N);
        printf("%d", ans[0]);
        for (int j = 1; j < N; ++j) {
            printf(" %d", ans[j]);
        }
        printf("\n");
    }

    return 0;
}