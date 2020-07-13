#include <bits/stdc++.h>

using namespace std;

// Don't use std::next_permutation for practice
// https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
bool next_permutation(vector<int>& A) {
    const int N = A.size();
    int i = N - 2;
    while (i >= 0 && A[i] >= A[i+1]) --i;
    if (i == -1) return false;
    int j = i;
    while (j + 1 < N && A[j+1] >= A[i]) j++;
    swap(A[i], A[j]);
    reverse(A.begin() + i + 1, A.end());
    return true;
}

// Don't use std::prev_permutation for practice
// https://www.geeksforgeeks.org/lexicographically-previous-permutation-in-c/
bool prev_permutation(vector<int>& A) {
    const int N = A.size();
    int i = N - 2;
    while (i >= 0 && A[i] <= A[i+1]) --i;
    if (i == -1) return false;
    int j = i;
    while (j+1 < N && A[j+1] <= A[i]) j++;
    swap(A[i], A[j]);
    reverse(A.begin() + i + 1, A.end());
    return true;
}

void dump(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> prev, next;

    prev = next = A;
    if (prev_permutation(prev)) {
        dump(prev);
    }
    dump(A);
    if (next_permutation(next)) {
        dump(next);
    }

    return 0;
}