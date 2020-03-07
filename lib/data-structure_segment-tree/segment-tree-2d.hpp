#pragma once

#include <algorithm>
#include <vector>

// Query: find the sum on some submatrix a[xl...xr,yl...yr]
// Update: perform modification of individual matrix elements a[x,y] = p
class SegmentTree {
    using row = std::vector<int>;
    using matrix = std::vector<row>;
    matrix m_tree;
    int m_size_x, m_size_y;

public:
    SegmentTree(int n, int m)
        : m_size_x(n)
        , m_size_y(m)
        , m_tree(n * 4, row(m * 4))
    {
        // Do nothing
    }

    int size_x() {
        return m_size_x;
    }
    int size_y() {
        return m_size_y;
    }
    // O(16NM)
    void build(matrix& matrix) {
        m_size_x = matrix.size();
        m_size_y = m_size_x ? matrix[0].size() : 0;
        m_tree.resize(m_size_x * 4);
        std::fill(m_tree.begin(), m_tree.end(), row(m_size_y * 4));
        build_x(matrix, 0, 0, m_size_x);
    }
    // O(log N log M)
    int sum(int lx, int rx, int ly, int ry) {
        lx = std::max(lx, 0);
        rx = std::min(rx, m_size_x);
        ly = std::max(ly, 0);
        ry = std::min(ry, m_size_y);
        return sum_x(0, 0, m_size_x, lx, rx, ly, ry);
    }
    // O(log N + log M)
    bool update(int x, int y, int value) {
        if (x < 0 || x >= m_size_x) return false;
        if (y < 0 || y >= m_size_y) return false;
        update_x(0, 0, m_size_x, x, y, value);
        return true;
    }
    // O(NM log N log M) for simplicity
    void dump(matrix& buffer) {
        buffer.resize(m_size_x);
        std::fill(buffer.begin(), buffer.end(), row(m_size_y));
        for (int x = 0; x < m_size_x; ++x) {
            for (int y = 0; y < m_size_y; ++y) {
                buffer[x][y] = sum(x, x + 1, y, y + 1);
            }
        }
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }
    static constexpr int right(int v) {
        return v * 2 + 2;
    }
    void build_y(matrix& matrix, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ry - ly <= 0 || rx - lx <= 0) return;
        if (ry - ly == 1) {
            if (rx - lx == 1) {
                m_tree[vx][vy] = matrix[lx][ly];
            } else {
                m_tree[vx][vy] = m_tree[left(vx)][vy] + m_tree[right(vx)][vy];
            }
        } else {
            const int my = (ly + ry) / 2;
            build_y(matrix, vx, lx, rx, left(vy), ly, my);
            build_y(matrix, vx, lx, rx, right(vy), my, ry);
            m_tree[vx][vy] = m_tree[vx][left(vy)] + m_tree[vx][right(vy)];
        }
    }
    void build_x(matrix& matrix, int vx, int lx, int rx) {
        if (rx - lx <= 0) return;
        if (rx - lx > 1) {
            const int mx = (lx + rx) / 2;
            build_x(matrix, left(vx), lx, mx);
            build_x(matrix, right(vx), mx, rx);
        }
        build_y(matrix, vx, lx, rx, 0, 0, m_size_y);
    }
    int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ry - ly <= 0) {
            return 0;
        }
        if (ly == tly && ry == try_) {
            return m_tree[vx][vy];
        }
        const int tmy = (tly + try_) / 2;
        const int lhs = sum_y(vx, left(vy), tly, tmy, ly, std::min(ry,tmy));
        const int rhs = sum_y(vx, right(vy), tmy, try_, std::max(ly,tmy), ry);
        return lhs + rhs;
    }
    int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (rx - lx <= 0) {
            return 0;
        }
        if (lx == tlx && rx == trx) {
            return sum_y(vx, 0, 0, m_size_y, ly, ry);
        }
        const int tmx = (tlx + trx) / 2;
        const int lhs = sum_x(left(vx), tlx, tmx, lx, std::min(rx,tmx), ly, ry);
        const int rhs = sum_x(right(vx), tmx, trx, std::max(lx,tmx), rx, ly, ry);
        return lhs + rhs;
    }
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int value) {
        if (ry - ly <= 0 || rx - lx <= 0) return;
        if (ry - ly == 1) {
            if (rx - lx == 1) {
                m_tree[vx][vy] = value;
            } else {
                m_tree[vx][vy] = m_tree[left(vx)][vy] + m_tree[right(vx)][vy];
            }
        } else {
            const int my = (ly + ry);
            if (y < my) {
                update_y(vx, lx, rx, left(vy), ly, my, x, y, value);
            } else {
                update_y(vx, lx, rx, right(vy), my, ry, x, y, value);
            }
            m_tree[vx][vy] = m_tree[vx][left(vy)] + m_tree[vx][right(vy)];
        }
    }
    void update_x(int vx, int lx, int rx, int x, int y, int value) {
        if (rx - lx <= 0) return;
        if (rx - lx > 1) {
            const int mx = (lx + rx) / 2;
            if (x < mx) {
                update_x(left(vx), lx, mx, x, y, value);
            } else {
                update_x(right(vx), mx, rx, x, y, value);
            }
        }
        update_y(vx, lx, rx, 0, 0, m_size_y, x, y, value);
    }
};