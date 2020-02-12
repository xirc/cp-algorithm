// https://codeforces.com/contest/727/problem/A

#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

bool solve(long long a, long long b, deque<long long>& ans) {
    if (a == b) return true;
    if (a > b) return false;

    long long na1 = 2 * a;
    ans.push_back(na1);
    bool yes1 = solve(na1, b, ans);
    if (yes1) return true;
    ans.pop_back();
    
    long long na2 = 10 * a + 1;
    ans.push_back(na2);
    bool yes2 = solve(na2, b, ans);
    if (yes2) return true;
    ans.pop_back();

    return false;
}

deque<long long> solve(long long a, long long b) {
    deque<long long> ans;
    if (a == b) {
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
    ans.push_back(a);
    auto yes = solve(a, b, ans);
    if (yes) return ans;
    return deque<long long>();
}

int main() {
    long long a, b;
    cin >> a >> b;

    auto ans = solve(a, b);
    if (ans.size() == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}