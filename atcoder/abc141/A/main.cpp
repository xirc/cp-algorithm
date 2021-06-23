#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string,string> next = {
	    {"Sunny", "Cloudy"},
	    {"Cloudy", "Rainy"},
	    {"Rainy", "Sunny"},
    };

    string S;
    cin >> S;
    cout << next[S] << endl;

    return 0;
}