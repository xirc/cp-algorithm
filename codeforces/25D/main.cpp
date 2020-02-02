// http://codeforces.com/contest/25/problem/D

#include <iostream>
#include <vector>

using namespace std;

struct Node { int parent, rank; };
class UnionFindTree {
    vector<Node> nodes;

public:
    UnionFindTree(int size): nodes(size) {
        for (int i = 0; i < size; ++i) {
            nodes[i] = Node { i, 0 };
        }
    }
    Node find_set(int index) {
        if (index < 0 || index >= nodes.size()) throw;
        if (nodes[index].parent != index) {
            // Path Compression
            auto root = find_set(nodes[index].parent);
            nodes[index].parent = root.parent;
        }
        return nodes[index];
    }
    bool is_same_set(int index1, int index2) {
        index1 = find_set(index1).parent;
        index2 = find_set(index2).parent;
        return index1 == index2;
    }
    void union_set(int index1, int index2) {
        index1 = find_set(index1).parent;
        index2 = find_set(index2).parent;

        if (index1 == index2) {
            return;
        }
        if (nodes[index1].rank < nodes[index2].rank) {
            swap(index1, index2);
        }
        nodes[index2].parent = index1;
        if (nodes[index1].rank == nodes[index2].rank) {
            nodes[index1].rank++;
        }
    }
};


int main() {
    int n;
    
    cin >> n;

    UnionFindTree tree(n);
    vector<pair<int,int>> old_pairs;
    vector<pair<int,int>> new_pairs;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (tree.is_same_set(a, b)) {
            old_pairs.push_back({ a, b });
        } else {
            tree.union_set(a, b);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (tree.is_same_set(0, i)) {
            continue;
        }
        tree.union_set(0, i);
        new_pairs.push_back({0, i});
    }


    cout << new_pairs.size() << endl;
    for (int i = 0; i < new_pairs.size(); ++i) {
        auto old_pair = old_pairs[i];
        auto new_pair = new_pairs[i];
        cout << old_pair.first + 1 << " " << old_pair.second + 1 << " ";
        cout << new_pair.first + 1 << " " << new_pair.second + 1 << endl;
    }

    return 0;
}