#include <bits/stdc++.h>

using namespace std;

struct BinaryHeap {
    int H;
    vector<int> heap;
    void restore(const vector<int>& array) {
        H = array.size();
        heap = vector<int>(array.begin(), array.end());
    }
    void print() {
        for (int v = 0; v < H; ++v) {
            cout << "node " << (v+1) << ": ";
            cout << "key = " << heap[v] << ", ";
            int p = parent(v);
            if (p != -1) cout << "parent key = " << heap[p] << ", ";
            int l = left(v);
            if (l != -1) cout << "left key = " << heap[l] << ", ";
            int r = right(v);
            if (r != -1) cout << "right key = " << heap[r] << ", ";
            cout << endl;
        }
    }
private:
    int parent(int v) {
        if (v == 0) return - 1;
        return (v - 1) / 2;
    }
    int left(int v) {
        int l = v * 2 + 1;
        return l < H ? l : -1;
    }
    int right(int v) {
        int r = v * 2 + 2;
        return r < H ? r : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    BinaryHeap heap;

    int N;
    cin >> N;
    vector<int> buf(N);
    for (int i = 0; i < N; ++i) {
        cin >> buf[i];
    }

    heap.restore(buf);
    heap.print();

    return 0;
}