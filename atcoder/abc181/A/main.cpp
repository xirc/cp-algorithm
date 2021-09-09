#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    auto color = (N % 2 == 0) ? "White" : "Black";
    cout << color << endl;

    return 0;
}