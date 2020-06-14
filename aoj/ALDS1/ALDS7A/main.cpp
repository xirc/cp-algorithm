#include <bits/stdc++.h>

using namespace std;

struct Node {
    int parent;
    string type;
    int depth;
    vector<int> children;
};

int N;
int root;
vector<Node> nodes;

void resolve_root() {
    vector<bool> is_root(N, true);
    for (auto n : nodes) {
        for (auto v : n.children) {
            is_root[v] = false;
        }
    }
    root = -1;
    for (int i = 0; i < N; ++i) {
        if (is_root[i]) {
            root = i;
            return;
        }
    }
}

void update_tree_info(int v, int p = -1, int d = 0) {
    nodes[v].parent = p;
    if (v == root) {
        nodes[v].type = "root";
    } else if (nodes[v].children.size()) {
        nodes[v].type = "internal node";
    } else {
        nodes[v].type = "leaf";
    }
    nodes[v].depth = d;
    for (int u : nodes[v].children) {
        update_tree_info(u, v, d+1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    nodes.assign(N, Node());
    for (int i = 0; i < N; ++i) {
        int id, k;
        cin >> id >> k;
        nodes[id].children.assign(k, -1);
        for (int j = 0; j < k; ++j) {
            cin >> nodes[id].children[j];
        }
    }

    resolve_root();
    if (root == -1) throw;
    update_tree_info(root);

    for (int i = 0; i < N; ++i) {
        cout << "node " << i << ": "
            << "parent = " << nodes[i].parent << ", "
            << "depth = " << nodes[i].depth << ", "
            << nodes[i].type << ", ";
        cout << "[";
        for (int j = 0; j < nodes[i].children.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << nodes[i].children[j];
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}