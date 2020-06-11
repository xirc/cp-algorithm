#include <bits/stdc++.h>

using namespace std;

int selection_sort(vector<int>& array) {
    int swap_count = 0;
    for (int i = 0; i < array.size(); ++i) {
        int mini = i;
        for (int j = i+1; j < array.size(); ++j) {
            if (array[j] < array[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(array[i], array[mini]);
            swap_count++;
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

    int swap_count = selection_sort(A);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << swap_count << endl;

    return 0;
}