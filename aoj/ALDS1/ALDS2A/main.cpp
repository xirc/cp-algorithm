#include <bits/stdc++.h>

using namespace std;

int bubble_sort(vector<int>& array) {
    int swap_count = 0;
    for (int i = 0; i < array.size(); ++i) {
        for (int j = array.size() - 1; j > i; --j) {
            if (array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
                swap_count++;
            }
        }
    }
    return swap_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int count = bubble_sort(A);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}