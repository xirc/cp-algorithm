#include <bits/stdc++.h>

using namespace std;

vector<int> seive(int N) {
    vector<bool> prime(N+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
 
    auto ps = seive(55555);
    auto as = vector<int>();
    for (auto p : ps) {
        if (p % 5 == 1) as.push_back(p);
    }
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " " ;
        cout << as[i];
    }
    cout << endl;

    return 0;
}