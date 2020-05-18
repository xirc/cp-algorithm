// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A

#include <iostream>
#include <vector>
#include <algorithm>

class UnionFindTree {
public:
    struct node { int parent, rank; };

private:
    int m_size;
    std::vector<node> m_nodes;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_nodes(size)
    {
        for (int i = 0; i < size; ++i) {
            m_nodes[i] = { i, 0 };
        }
    }
    int size() {
        return m_size;
    }
    // O(a(N))
    node find_set(int index) {
        throw_if_invalid_index(index);
        if (index != m_nodes[index].parent) {
            // Path Compression
            m_nodes[index] = find_set(m_nodes[index].parent);
        }
        return m_nodes[index];
    }
    // O(a(N))
    void union_set(int a, int b) {
        throw_if_invalid_index(a);
        throw_if_invalid_index(b);
        a = find_set(a).parent;
        b = find_set(b).parent;
        if (a == b) {
            return;
        }
        if (m_nodes[a].rank < m_nodes[b].rank) {
            std::swap(a, b);
        }
        m_nodes[b].parent = a;
        if (m_nodes[a].rank == m_nodes[b].rank) {
            m_nodes[a].rank++;
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    
    UnionFindTree tree(N);
    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            tree.union_set(x, y);
        } else if (c == 1) {
            auto nx = tree.find_set(x);
            auto ny = tree.find_set(y);
            cout << (nx.parent == ny.parent) << endl;
        } else throw;
    }

    return 0;
}