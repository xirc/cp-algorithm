// https://www.spoj.com/problems/RMQSQ/

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class SparseTable {
    // table[k][i] = the min between table[0][j] where j in [i,i+2**k]
    // table[k][i] = the min between table[k-1][i] and table[k-1][i+2**(k-1)]
    vector<vector<int>> table;
    int N;
    int K;

public:
    // O(N logN)
    void initialize(vector<int> &array) {
        N = array.size();
        K = ceil(log2(N));
        table = vector<vector<int>>(K);
        for (int i = 0; i < K; ++i) {
            table[i] = vector<int>(N);
        }

        copy(array.begin(), array.end(), table[0].begin());
        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < N; ++i) {
                int i2 = i + (1 << (k-1));
                if (i2 >= N) continue;
                table[k][i] = min(table[k-1][i], table[k-1][i2]);
            }
        }
    }

    // O(1)
    // the min between table[0][i] where i in range [l, r)
    int query(int l, int r) {
        int w = r - l;
        int k = log2(w);
        return min(table[k][l], table[k][r - (1 << k)]);
    }
};

int main() {
    int N, Q;

    scanf("%d", &N);

    vector<int> array(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &array[i]);
    }

    SparseTable table;
    table.initialize(array);

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = table.query(l, r+1);
        printf("%d\n", ans);
    }

    return 0;
}