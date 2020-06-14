#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right;
};

int N;
vector<Node> nodes;

int resolve_root() {
    vector<bool> referenced(N, false);
    for (int i = 0; i < N; ++i) {
        int l = nodes[i].left, r = nodes[i].right;
        if (l != -1) referenced[l] = true;
        if (r != -1) referenced[r] = true;
    }
    for (int i = 0; i < N; ++i) {
        if (!referenced[i]) return i;
    }
    return -1;
}

void dump_preoder(int v) {
    if (v == -1) return;
    cout << " " << v;
    dump_preoder(nodes[v].left);
    dump_preoder(nodes[v].right);
}

void dump_inorder(int v) {
    if (v == -1) return;
    dump_inorder(nodes[v].left);
    cout << " " << v;
    dump_inorder(nodes[v].right);
}

void dump_postorder(int v) {
    if (v == -1) return;
    dump_postorder(nodes[v].left);
    dump_postorder(nodes[v].right);
    cout << " " << v;
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

    int r = resolve_root();
    
    cout << "Preorder" << endl;
    dump_preoder(r);
    cout << endl;
    cout << "Inorder" << endl;
    dump_inorder(r);
    cout << endl;
    cout << "Postorder" << endl;
    dump_postorder(r);
    cout << endl;

    return 0;
}