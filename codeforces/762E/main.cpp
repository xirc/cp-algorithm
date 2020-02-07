// https://codeforces.com/contest/762/problem/E

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class Treap {
protected:
    struct Node {
        int key;
        int count;
        int priority;
        Node *left, *right;
        Node(int key, int priority)
            : key(key)
            , count(1)
            , priority(priority)
            , left(nullptr)
            , right(nullptr)
            {
                // Do nothing
            }
    };
    using Tree = Node*;

    std::mt19937 random;
    Tree root = nullptr;

public:
    // O(logN)
    void insert(int key) {
        insert(root, new Node(key, random()));
    }
    // O(logN)
    long long count(int l, int r) {
        return count(root, l, r);
    }

protected:
    long long count(Tree tree) {
        return tree ? tree->count : 0;
    }
    void pushup(Tree tree) {
        if (tree) {
            tree->count = 1 + count(tree->left) + count(tree->right);
        }
    }
    void pushdown(Tree tree) {
        pushup(tree);
    }
    // O(logN)
    // left: <= key, right: > key
    void split(Tree tree, int key, Tree& left, Tree& right) {
        if (!tree) {
            left = right = nullptr;
            return;
        }
        pushdown(tree);
        if (key < tree->key) {
            split(tree->left, key, left, tree->left);
            right = tree;
        } else {
            split(tree->right, key, tree->right, right);
            left = tree;
        }
        pushup(tree);
    }
    // O(logN)
    void merge(Tree &tree, Tree left, Tree right) {
        pushdown(left);
        pushdown(right);
        if (!left || !right) {
            tree = left ? left : right;
        } else if (left->priority > right->priority) {
            merge(left->right, left->right, right);
            tree = left;
        } else {
            merge(right->left, left, right->left);
            tree = right;
        }
        pushup(tree);
    }
    // O(logN)
    void insert(Tree &tree, Tree item) {
        if (!tree) {
            tree = item;
            return;
        }
        pushdown(tree);
        if (item->priority > tree->priority) {
            split(tree, item->key, item->left, item->right);
            tree = item;
        } else {
            insert(item->key < tree->key ? tree->left : tree->right, item);
        }
        pushup(tree);
    }
    // O(logN)
    // count elements where key = [l, r)
    long long count(Tree &tree, int l, int r) {
        Tree t1, t2, t3;
        long long ans;
        split(tree, l - 1, t1, t2);
        split(t2, r - 1, t2, t3);
        ans = count(t2);
        merge(t2, t2, t3);
        merge(tree, t1, t2);
        return ans;
    }
};

struct Station {
    int x, r, f;
    bool operator<(const Station& other){
        return r < other.r;
    }
};

const int MAX_F = 1e4 + 11;
int N, K;
vector<Station> stations;
vector<Treap> treap_by_freq(MAX_F);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    stations.assign(N, Station());
    for (int i = 0; i < N; ++i) {
        int x, r, f;
        cin >> x >> r >> f;
        stations[i] = Station { x, r, f };
    }

    sort(stations.begin(), stations.end());
    reverse(stations.begin(), stations.end());

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        auto station = stations[i];
        for (int df = -K; df <= K; ++df) {
            int f = station.f + df;
            if (f <= 0) continue;
            int l = station.x - station.r;
            int r = station.x + station.r;
            ans += treap_by_freq[f].count(l, r+1);
        }
        treap_by_freq[station.f].insert(station.x);
    }
    cout << ans << endl;

    return 0;
}