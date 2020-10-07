#include <bits/stdc++.h>

using namespace std;

int digsum(int V) {
    int sum = 0;
    while (V > 0)
    {
        sum += V % 10;
        V /= 10;
    }
    return sum;
}

int solve(int N, int A, int B) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int sum = digsum(i);
        if (sum >= A && sum <= B) {
            ans += i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;
    cout << solve(N, A, B) << endl;

    return 0;
}