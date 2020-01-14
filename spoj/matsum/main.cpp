// https://www.spoj.com/problems/MATSUM/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

class BIT {
    int N;
    // 1-index-base
    vector<vector<int>> matrix;
public:
    BIT(int n) {
        N = n + 1;
        matrix = vector<vector<int>>(N);
        for (int i = 0; i < N; ++i) {
            matrix[i] = vector<int>(N, 0);
        }
    }
    // O(N*N)
    void clear() {
        for (int i = 0; i < N; ++i) {
            fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }
    // add v to matrix[x][y]
    // O((logN)**2)
    void add(int x, int y, int v) {
        if (x < 0 || y < 0) {
            return;
        }
        x++;
        y++;
        for (int ix = x; ix < N; ix += ix&-x) {
            for (int iy = y; iy < N; iy += iy&-iy) {
                matrix[ix][iy] += v;
            }
        }
    }
    // sum of matrix[i][j] where 0 <= i < x and 0 <= j < y
    // O((logN)**2)
    int sum(int x, int y) {
        if (x <= 0 || y <= 0) {
            return 0;
        }
        int v = 0;
        for (int ix = x; ix > 0; ix -= ix&-ix) {
            for (int iy = y; iy > 0; iy -= iy&-iy) {
                v += matrix[ix][iy];
            }
        }
        return v;
    }
    // sum of matrix[i][j] where x1 <= i < x2 and y1 <= j < y2
    // O((logN)**2)
    int sum(int x1, int y1, int x2, int y2) {
        int a1 = sum(x2, y2);
        int a2 = sum(x2, y1);
        int a3 = sum(x1, y2);
        int a4 = sum(x1, y1);
        return a1 - a2 - a3 + a4;
    }
};

int main() {
    const int MAX_N = 1024;
    int T, N;
    BIT bit(MAX_N);

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        bit.clear();

        char cmd[4];
        int x1, y1, x2, y2, v;
        scanf("%d", &N);
        while (true) {
            scanf("%3s", cmd);
            if (strcmp(cmd, "END") == 0) {
                break;
            } else if (strcmp(cmd, "SET") == 0) {
                scanf("%d %d %d", &x1, &y1, &v);
                int ov = bit.sum(x1, y1, x1 + 1, y1 + 1);
                bit.add(x1, y1, -ov);
                bit.add(x1, y1, v);
            } else if (strcmp(cmd, "SUM") == 0) {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ans = bit.sum(x1, y1, x2+1, y2+1);
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}