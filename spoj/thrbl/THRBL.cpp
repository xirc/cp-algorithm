// https://www.spoj.com/problems/THRBL/

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class SparseTable {
private:
    int N;
    int K;
    // table[k][i] = the max between table[0][j] where j in [i, i+2**k)
    // table[k][i] = the max between table[k-1][i] and table[k-1][i-(2**(k-1))]
    vector<vector<int>> table;

public:
    SparseTable(vector<int>& array) {
        N = array.size();
        K = ceil(log2(N));

        table = vector<vector<int>>(K);
        for (int i = 0; i < K; ++i) {
            table[i] = vector<int>(N, -1);
        }

        copy(array.begin(), array.end(), table[0].begin());
        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < N; ++i) {
                int i2 = i + (1 << (k - 1));
                if (i2 >= N) continue;
                table[k][i] = max(table[k-1][i], table[k-1][i2]);
            }
        }
    }
    
    // find the max between table[0][k] where k in [l, r)
    int query(int l, int r) {
        int w = r - l;
        int k = log2(w);
        return max(table[k][l], table[k][r - (1 << k)]);
    }
};

int main() {
    int N, M;
    int A, B;

    scanf("%d %d", &N, &M);

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &array[i]);
    }

    SparseTable table(array);

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &A, &B);
        A--; B--;

        // NOTE: Exclude B
        if (table.query(A, B) <= array[A]) {
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}