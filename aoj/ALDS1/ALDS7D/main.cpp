#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right;
};

vector<Node> nodes;

int reconstruct_rec(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.size() != inorder.size()) throw;
    if (preorder.size() == 0) {
        return -1;
    }

    int v = preorder[0];
    int pos;
    for (pos = 0; pos < inorder.size() && inorder[pos] != v; ++pos);
    // inorder[pos] == v
    vector<int> l_preorder(preorder.begin() + 1, preorder.begin() + 1 + pos);
    vector<int> l_inorder(inorder.begin(), inorder.begin() + pos);
    vector<int> r_preorder(preorder.begin() + 1 + pos, preorder.end());
    vector<int> r_inorder(inorder.begin() + pos + 1, inorder.end());

    int l = reconstruct_rec(l_preorder, l_inorder);
    int r = reconstruct_rec(r_preorder, r_inorder);
    nodes[v].left = l;
    nodes[v].right = r;
    return v;
}

int reconstruct(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.size() != inorder.size()) throw;
    nodes.assign(preorder.size(), Node());
    return reconstruct_rec(preorder, inorder);
}

void make_postorder(int v, vector<int>& result) {
    if (v == -1) return;
    make_postorder(nodes[v].left, result);
    make_postorder(nodes[v].right, result);
    result.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> preorder(N), inorder(N);
    for (int i = 0; i < N; ++i) {
        cin >> preorder[i];
        preorder[i]--;
    }
    for (int i = 0; i < N; ++i) {
        cin >> inorder[i];
        inorder[i]--;
    }

    int r = reconstruct(preorder, inorder);
    vector<int> postorder;
    make_postorder(r, postorder);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << postorder[i]+1;
    }
    cout << endl;

    return 0;
}