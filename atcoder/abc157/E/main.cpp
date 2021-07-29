#include <bits/stdc++.h>

template<class T, class E>
class SegmentTree {
public:
    using value_type_T = T;
    using value_type_E = E;
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&, const E&)>;

protected:
    F query_op;
    T query_id;
    G update_op;
    int N, M;
    std::vector<T> tree;

public:
    // O(N)
    SegmentTree(
        int n,
        const F& query_op, const T& query_id,
        const G& update_op
    )
        : query_op(query_op)
        , query_id(query_id)
        , update_op(update_op)
    {
        build(std::vector<T>(n, query_id));
    }
    // O(N)
    template <class Query, class Update>
    SegmentTree(int n, const Query& query, const Update& update)
        : SegmentTree(
            n,
            std::bind(&Query::operator(), query, std::placeholders::_1, std::placeholders::_2),
            query.id,
            std::bind(&Update::operator(), update, std::placeholders::_1, std::placeholders::_2)
        )
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        M = 4 * N;
        tree.assign(M, query_id);
        build(array, 0, 0, N);
    }
    // find the value in range [l, r)
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, N, std::max(l,0), std::min(r,N));
    }
    // update the value at index = [0, n)
    // O(log N)
    bool update(int index, const E& value) {
        if (index < 0 || index >= N) {
            return false;
        }
        update(0, 0, N, index, value);
        return true;
    }
    // O(N logN)
    void dump(std::vector<T>& buffer) {
        buffer.clear();
        for (int i = 0; i < N; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }

protected:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = array[tl];
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            tree[v] = query_op(tree[vl], tree[vr]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return query_id;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto sl = query(vl, tl, tm, l, std::min(r,tm));
        const auto sr = query(vr, tm, tr, std::max(l,tm), r);
        return query_op(sl, sr);
    }
    void update(int v, int tl, int tr, int index, const E& value) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = update_op(tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            if (index < tm) {
                update(vl, tl, tm, index, value);
            } else {
                update(vr, tm, tr, index, value);
            }
            tree[v] = query_op(tree[vl], tree[vr]);
        }
    }
};

using namespace std;
using ll = int64_t;
using ff = long double;

struct Query {
    const bitset<26> id = bitset<26>();
    bitset<26> operator()(bitset<26> const& lhs, bitset<26> const& rhs) const {
        return lhs | rhs;
    }
};
struct Update {
    bitset<26> operator()(bitset<26> const& lhs, pair<int,bool> const& value) const {
        auto res = lhs;
        res[value.first] = value.second;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    string S;

    cin >> N >> S;

    SegmentTree<bitset<26>, pair<int,bool>> tree(N, Query(), Update());
    for (int i = 0; i < N; ++i) {
        tree.update(i, make_pair(S[i] - 'a', true));
    }

    cin >> Q;
    for (int qq = 0; qq < Q; ++qq) {
        int t;
        cin >> t;
        if (t == 1) {
            int i; char c;
            cin >> i >> c;
            --i;
            tree.update(i, make_pair(S[i] - 'a', false));
            S[i] = c;
            tree.update(i, make_pair(S[i] - 'a', true));
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            --l;
            cout << tree.query(l, r).count() << endl;
        } else throw;
    }

    return 0;
}