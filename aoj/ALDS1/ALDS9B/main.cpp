#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>& A, int index) {
    const int N = A.size();
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxi = index;
    if (left < N && A[left] > A[maxi]) {
        maxi = left;
    }
    if (right < N && A[right] > A[maxi]) {
        maxi = right;
    }
    if (maxi != index) {
        swap(A[index], A[maxi]);
        heapify(A, maxi);
    }
}

void heapify(vector<int>& A) {
    const int N = A.size();
    for (int i = N - 1; i >= 0; --i) {
        heapify(A, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> heap(N);
    for (int i = 0; i < N; ++i) {
        cin >> heap[i];
    }
    heapify(heap);
    for (int v : heap) {
        cout << " " << v;
    }
    cout << endl;

    return 0;
}