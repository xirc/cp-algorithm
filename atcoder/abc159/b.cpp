// https://atcoder.jp/contests/abc159/tasks/abc159_b

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s) {
    const int N = s.size();
    for (int i = 0; i < N / 2; ++i) {
        if (s[i] != s[N - 1 - i]) return false;
    }
    return true;
}

bool solve(string s) {
    const int N = s.size();
    auto s1 = s.substr(0, (N-1)/2);
    auto s2 = s.substr((N+3)/2 - 1);
    return
        is_palindrome(s) &&
        is_palindrome(s1) &&
        is_palindrome(s2);
}

int main() {
    string S;
    cin >> S;
    auto ans = solve(S);
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}