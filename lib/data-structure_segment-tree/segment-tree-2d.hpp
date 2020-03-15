#pragma once

#include <vector>
#include <algorithm>
#include <functional>

// SegmentTree (PointUpdate,RangeQuery)
// Memory O(NM)
// Query (logN logM)
// Update (logN logM)
template <class T, class E>
class SegmentTree {
public:
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;

protected:
    F query_op;
    T query_id;
    G update_op;
    int N, M;
    std::vector<std::vector<T>> m_tree;

public:
    // O(NM)
    SegmentTree(
        int n,
        int m,
        const F& query_op,
        const T& query_id,
        const G& update_op
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
    {
        build(std::vector<std::vector<T>>(n, std::vector<T>(m, query_id)));
    }
    // O(NM)
    template <class Query, class Update>
    SegmentTree(
        int n,
        int m,
        const Query& query,
        const Update& update
    )
        : SegmentTree(
            n,
            m,
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2),
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2)
        )
    {
        // Do nothing
    }
    // O(1)
    std::pair<int,int> size() {
        return { N, M };
    }
    // O(MN)
    void build(const std::vector<std::vector<T>>& matrix) {
        N = matrix.size();
        M = N ? matrix[0].size() : 0;
        m_tree.assign(4 * N, std::vector<T>(4 * M));
        build_x(matrix, 0, 0, N);
    }
    // O(log N log M)
    // [lx,rx)
    // [ly,ry)
    // lx = [0,N), rx = [0,N]
    // ly = [0,M), ry = [0,M)
    T query(int lx, int rx, int ly, int ry) {
        lx = std::max(lx, 0);
        rx = std::min(rx, N);
        ly = std::max(ly, 0);
        ry = std::min(ry, M);
        return query_x(0, 0, N, lx, rx, ly, ry);
    }
    // O(log N log M)
    // x = [0,N)
    // y = [0,M)
    bool update(int x, int y, const E& value) {
        if (x < 0 || x >= N) return false;
        if (y < 0 || y >= M) return false;
        update_x(0, 0, N, x, y, value);
        return true;
    }
    // O(NM log N log M)
    void dump(std::vector<std::vector<T>>& buffer) {
        buffer.assign(N, std::vector<T>(M));
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < M; ++y) {
                buffer[x][y] = query(x, x + 1, y, y + 1);
            }
        }
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build_y(const std::vector<std::vector<T>>& matrix, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ry - ly <= 0 || rx - lx <= 0) return;
        if (ry - ly == 1) {
            if (rx - lx == 1) {
                m_tree[vx][vy] = matrix[lx][ly];
            } else {
                m_tree[vx][vy] = query_op(m_tree[left(vx)][vy], m_tree[right(vx)][vy]);
            }
        } else {
            const int my = (ly + ry) / 2;
            build_y(matrix, vx, lx, rx, left(vy), ly, my);
            build_y(matrix, vx, lx, rx, right(vy), my, ry);
            m_tree[vx][vy] = query_op(m_tree[vx][left(vy)], m_tree[vx][right(vy)]);
        }
    }
    void build_x(const std::vector<std::vector<T>>& matrix, int vx, int lx, int rx) {
        if (rx - lx <= 0) return;
        if (rx - lx > 1) {
            const int mx = (lx + rx) / 2;
            build_x(matrix, left(vx), lx, mx);
            build_x(matrix, right(vx), mx, rx);
        }
        build_y(matrix, vx, lx, rx, 0, 0, M);
    }
    T query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ry - ly <= 0) {
            return query_id;
        }
        if (ly == tly && ry == try_) {
            return m_tree[vx][vy];
        }
        const int tmy = (tly + try_) / 2;
        const auto lhs = query_y(vx, left(vy), tly, tmy, ly, std::min(ry,tmy));
        const auto rhs = query_y(vx, right(vy), tmy, try_, std::max(ly,tmy), ry);
        return query_op(lhs, rhs);
    }
    T query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (rx - lx <= 0) {
            return query_id;
        }
        if (lx == tlx && rx == trx) {
            return query_y(vx, 0, 0, M, ly, ry);
        }
        const int tmx = (tlx + trx) / 2;
        const auto lhs = query_x(left(vx), tlx, tmx, lx, std::min(rx,tmx), ly, ry);
        const auto rhs = query_x(right(vx), tmx, trx, std::max(lx,tmx), rx, ly, ry);
        return query_op(lhs, rhs);
    }
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, const E& value) {
        if (ry - ly <= 0 || rx - lx <= 0) return;
        if (ry - ly == 1) {
            if (rx - lx == 1) {
                m_tree[vx][vy] = update_op(m_tree[vx][vy], value);
            } else {
                m_tree[vx][vy] = query_op(m_tree[left(vx)][vy], m_tree[right(vx)][vy]);
            }
        } else {
            const int my = (ly + ry) / 2;
            if (y < my) {
                update_y(vx, lx, rx, left(vy), ly, my, x, y, value);
            } else {
                update_y(vx, lx, rx, right(vy), my, ry, x, y, value);
            }
            m_tree[vx][vy] = query_op(m_tree[vx][left(vy)], m_tree[vx][right(vy)]);
        }
    }
    void update_x(int vx, int lx, int rx, int x, int y, const E& value) {
        if (rx - lx <= 0) return;
        if (rx - lx > 1) {
            const int mx = (lx + rx) / 2;
            if (x < mx) {
                update_x(left(vx), lx, mx, x, y, value);
            } else {
                update_x(right(vx), mx, rx, x, y, value);
            }
        }
        update_y(vx, lx, rx, 0, 0, M, x, y, value);
    }
};