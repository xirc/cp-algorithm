#include <bits/stdc++.h>

using namespace std;

int insertion_sort(vector<int>& A, int G) {
    int count = 0;
    for (int i = G; i < A.size(); ++i) {
        int v = A[i];
        int j = i - G;
        while (j >= 0 && A[j] > v) {
            A[j+G] = A[j];
            count++;
            j -= G;
        }
        A[j+G] = v;
    }
    return count;
}

vector<int> make_shell_sort_interval(int N) {
    vector<int> G = { 1 };
    for (int h = 4; h < N && G.size() <= 100; h = 3 * h + 1) {
        G.push_back(h);
    }
    reverse(G.begin(), G.end());
    return G;
}

pair<int,vector<int>> shell_sort(vector<int>& A) {
    int count = 0;
    auto G = make_shell_sort_interval(A.size());
    for (int i = 0; i < G.size(); ++i) {
        count += insertion_sort(A, G[i]);
    }
    return { count, G };
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

    int count;
    vector<int> G;
    tie(count, G) = shell_sort(A);

    cout << G.size() << endl;
    for (int i = 0; i < G.size(); ++i) {
        if (i > 0) cout << " ";
        cout << G[i];
    }
    cout << endl;

    cout << count << endl;

    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << endl;
    }

    return 0;
}