#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int min = *min_element(A.begin(), A.end());
    int max = *max_element(A.begin(), A.end());
    long long sum = accumulate(
        A.begin(), A.end(),
        0L, [](auto l, auto r) { return l + r;}
    );
    cout << min << " " << max << " " << sum << endl;

    return 0;
}