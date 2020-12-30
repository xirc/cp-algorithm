// https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B

#include <bits/stdc++.h>


template <typename T, typename U>
class UnionFindTree {
public:
    using D = std::function<T(size_t const idx)>;
    using E = std::function<U(U const& w)>;
    using F = std::function<void(T& node, T const& leader)>;
    using G = std::function<void(T& leader, T const& u, T const& v, U const& w)>;
    using H = std::function<void(T& leader, T& follower, T const& u, T const& v, U const& w)>;
    struct node {
        size_t leader;
        size_t rank;
        T value;
    };

private:
    size_t N;
    std::vector<node> nodes;
    D apply;
    E inverse;
    F compress;
    G unite_same;
    H unite_diff;

public:
    // Time: O(N)
    UnionFindTree(
        size_t const N = 0,
        D const& apply = [](size_t const idx) { return T(idx); },
        E const& inverse = std::negate<U>(),
        F const& compress = &T::compress,
        G const& unite_same = &T::unite_same,
        H const& unite_diff = &T::unite_diff
    )
        : N(N)
        , apply(apply)
        , inverse(inverse)
        , compress(compress)
        , unite_same(unite_same)
        , unite_diff(unite_diff)
    {
        nodes.reserve(N);
        for (size_t i = 0; i < N; ++i) {
            nodes.push_back({ i, 0, apply(i) });
        }
    }
    // Time: O(1)
    size_t size() {
        return N;
    }
    // v = [0,N)
    // Time: O(a(N))
    node find(size_t const v) {
        throw_if_invalid_index(v);
        auto& node = nodes[v];
        if (v != node.leader) {
            // Path Compression
            auto root = find(node.leader);
            node.leader = root.leader;
            node.rank = root.rank;
            compress(node.value, root.value);
        }
        return node;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool same(size_t const u, size_t const v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).leader == find(v).leader;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool unite(size_t u, size_t v, U w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        auto lu = find(u).leader;
        auto lv = find(v).leader;
        if (lu == lv) {
            unite_same(nodes[lu].value, nodes[u].value, nodes[v].value, w);
            return false;
        }
        if (nodes[lu].rank < nodes[lv].rank) {
            std::swap(lu, lv);
            std::swap(u, v);
            w = inverse(w);
        }
        nodes[lv].leader = lu;
        if (nodes[lu].rank == nodes[lv].rank) {
            nodes[lu].rank++;
        }
        unite_diff(nodes[lu].value, nodes[lv].value, nodes[u].value, nodes[v].value, w);
        return true;
    }

private:
    void throw_if_invalid_index(size_t const index) {
        if (index >= N) throw std::out_of_range("index out of range");
    }
};


using namespace std;

struct Data {
    long long value;
    Data(size_t i): value(0) {}
    static void compress(Data& node, const Data& leader) {
        node.value += leader.value;
    }
    static void unite_same(Data& leader, const Data& u, const Data& v, int const& w) {
        // Do nothing
    }
    static void unite_diff(Data& leader, Data& follower, const Data& a, const Data& b, int w) {
        w -= a.value;
        w += b.value;
        follower.value = -w;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    UnionFindTree<Data, int> tree(N);

    for (int i = 0; i < Q; ++i) {
        int c;
        cin >> c;
        if (c == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            tree.unite(y, x, z);
        } else if (c == 1) {
            int x, y; long long w;
            cin >> x >> y;
            if (tree.same(x, y)) {
                auto vx = tree.find(x);
                auto vy = tree.find(y);
                auto w = vy.value.value - vx.value.value;
                cout << w << endl;
            } else {
                cout << "?" << endl;
            }
        } else throw;
    }

    return 0;
}