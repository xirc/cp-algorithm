#include <iostream>
#include <random>
#include <vector>
#include <stack>

using namespace std;

void union_find_tree_init(vector<int>& tree) {
    for (int i = 0; i < tree.size(); ++i) {
        tree[i] = i;
    }
}

int union_find_tree_find_set(vector<int>& tree, int index) {
    if (index < 0 || index >= tree.size()) throw;
    if (tree[index] != index) {
        // Path Compression
        auto root = union_find_tree_find_set(tree, tree[index]);
        tree[index] = root;
    }
    return tree[index];
}

struct Query {
    // inclusive: [l, r]
    int l, r, idx;
};

// Arpa's trik, O(a(N)) on average
vector<int> solve(vector<int>& array, vector<pair<int,int>>& queries) {
    vector<vector<Query>> queries_by_r(array.size());
    for (int i = 0; i < queries.size(); ++i) {
        auto query = queries[i];
        auto l = query.first;
        auto r = query.second;
        queries_by_r[r].push_back(Query { l, r, i });
    }
    
    stack<int> s;
    vector<int> ans(array.size());
    vector<int> tree(array.size());

    union_find_tree_init(tree);
    for (int i = 0; i < array.size(); ++i) {
        while (!s.empty() && array[s.top()] > array[i]) {
            tree[s.top()] = i;
            s.pop();
        }
        s.push(i);
        for (auto q : queries_by_r[i]) {
            auto idx = union_find_tree_find_set(tree, q.l);
            ans[q.idx] = array[idx];
        }
    }

    return ans;
}

int main() {
    const int n = 10;
    const int m = 5;

    vector<int> array(n);
    vector<pair<int,int>> queries(m);
    random_device random;

    for (int i = 0; i < array.size(); ++i) {
        array[i] = random() % n;
    }
    for (int i = 0; i < queries.size(); ++i) {
        int l = random() % n, r = l + random() % (n - l);
        queries[i] = { l, r };
    }

    auto ans = solve(array, queries);

    cout << "array" << endl;
    for (int i = 0; i < array.size(); ++i) {
        if (i > 0) cout << " ";
        cout << array[i];
    }
    cout << endl;

    cout << "queries" << endl;
    for (int i = 0; i < queries.size(); ++i) {
        cout << queries[i].first << " " << queries[i].second << " -> " << ans[i] << endl;
    }

    return 0;
}