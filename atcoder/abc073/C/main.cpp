#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    set<int> ss;
    for (int i = 0; i < N; ++i) {
        int ai;
        cin >> ai;
        if (ss.count(ai) > 0) {
            ss.erase(ai);
        } else {
            ss.insert(ai);
        }
    }
    cout << ss.size() << endl;

    return 0;
}