#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
    string type;
};

int N;
int root;
vector<Node> nodes;

void resolve_root() {
    vector<bool> is_root(N, true);
    for (int i = 0; i < N; ++i) {
        const auto& n = nodes[i];
        if (n.left != -1) is_root[n.left] = false;
        if (n.right != -1) is_root[n.right] = false;
    }
    root = -1;
    for (int i = 0; i < N; ++i) {
        if (is_root[i]) {
            root = i;
            return;
        }
    }
}

void update_tree_info(int v, int p = -1, int depth = 0) {
    int l = nodes[v].left, r = nodes[v].right;
    nodes[v].parent = p;
    nodes[v].degree = 0;
    if (v == root) {
        nodes[v].sibling = -1;
    }
    if (l != -1) {
        nodes[v].degree++;
        nodes[l].sibling = r;
    }
    if (r != -1) {
        nodes[v].degree++;
        nodes[r].sibling = l;
    }
    nodes[v].depth = depth;
    if (v == root) {
        nodes[v].type = "root";
    } else if (l == -1 && r == -1) {
        nodes[v].type = "leaf";
    } else {
        nodes[v].type = "internal node";
    }
    nodes[v].height = 0;
    if (l != -1) {
        update_tree_info(l, v, depth + 1);
        nodes[v].height = max(nodes[v].height, nodes[l].height + 1);
    }
    if (r != -1) {
        update_tree_info(r, v, depth + 1);
        nodes[v].height = max(nodes[v].height, nodes[r].height + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    nodes.assign(N, Node());
    for (int i = 0; i < N; ++i) {
        int id, left, right;
        cin >> id >> left >> right;
        nodes[id].left = left;
        nodes[id].right = right;
    }

    resolve_root();
    if (root == -1) throw;
    update_tree_info(root);

    for (int i = 0; i < N; ++i) {
        auto& n = nodes[i];
        cout << "node " << i << ": "
            << "parent = " << n.parent << ", "
            << "sibling = " << n.sibling << ", "
            << "degree = " << n.degree << ", "
            << "depth = " << n.depth << ", "
            << "height = " << n.height << ", "
            << n.type << endl;
    }

    return 0;
}