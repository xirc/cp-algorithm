#include <bits/stdc++.h>

using namespace std;

void pushback(vector<int>& A, int x) {
    A.push_back(x);
}
void dump(const vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
void clear(vector<int>& A) {
    A.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> As;

    int N, Q;
    cin >> N >> Q;
    As.assign(N, vector<int>());
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int t, x;
            cin >> t >> x;
            pushback(As[t], x);
        } else if (type == 1) {
            int t;
            cin >> t;
            dump(As[t]);
        } else if (type == 2) {
            int t;
            cin >> t;
            clear(As[t]);
        } else throw;
    }

    return 0;
}