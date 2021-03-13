#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string aeiou = "aeiou";
    char c;
    cin >> c;
    auto is_vowel = aeiou.find(c) != string::npos;
    cout << (is_vowel ? "vowel" : "consonant") << endl;

    return 0;
}