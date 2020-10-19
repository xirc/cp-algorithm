#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A(5);
    int K;
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    cin >> K;
    
    int pmax = *max_element(A.begin(), A.end());
    int pmin = *min_element(A.begin(), A.end());
    bool good = abs(pmax - pmin) <= K;
    cout << (good ? "Yay!" : ":(") << endl;

    return 0;
}