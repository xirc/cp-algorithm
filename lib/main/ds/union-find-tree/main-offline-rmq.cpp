#include <bits/stdc++.h>

using namespace std;

void union_find_tree_init(vector<size_t>& tree) {
    for (size_t i = 0; i < tree.size(); ++i) {
        tree[i] = i;
    }
}

size_t union_find_tree_find_set(vector<size_t>& tree, size_t index) {
    if (index >= tree.size()) throw;
    if (tree[index] != index) {
        // Path Compression
        auto root = union_find_tree_find_set(tree, tree[index]);
        tree[index] = root;
    }
    return tree[index];
}

struct Query {
    // inclusive: [l, r]
    size_t l, r, idx;
};

// Arpa's trik, O(a(N)) on average
vector<int> solve(vector<int>& array, vector<pair<size_t,size_t>>& queries) {
    vector<vector<Query>> queries_by_r(array.size());
    for (size_t i = 0; i < queries.size(); ++i) {
        auto query = queries[i];
        auto l = query.first;
        auto r = query.second;
        queries_by_r[r].push_back(Query { l, r, i });
    }
    
    stack<size_t> s;
    vector<int> ans(array.size());
    vector<size_t> tree(array.size());

    union_find_tree_init(tree);
    for (size_t i = 0; i < array.size(); ++i) {
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
    const size_t n = 10;
    const size_t m = 5;

    vector<int> array(n);
    vector<pair<size_t,size_t>> queries(m);
    random_device random;

    for (size_t i = 0; i < array.size(); ++i) {
        array[i] = random() % n;
    }
    for (size_t i = 0; i < queries.size(); ++i) {
        size_t l = random() % n, r = l + random() % (n - l);
        queries[i] = { l, r };
    }

    auto ans = solve(array, queries);

    cout << "array" << endl;
    for (size_t i = 0; i < array.size(); ++i) {
        if (i > 0) cout << " ";
        cout << array[i];
    }
    cout << endl;

    cout << "queries" << endl;
    for (size_t i = 0; i < queries.size(); ++i) {
        cout << queries[i].first << " " << queries[i].second << " -> " << ans[i] << endl;
    }

    return 0;
}