#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_set<int> cs;
    int a, b, c;
    cin >> a >> b >> c;
    cs.insert(a);
    cs.insert(b);
    cs.insert(c);
    cout << cs.size() << endl;

    return 0;
}