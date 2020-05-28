#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string suits = "SHCD";
    int N;
    vector<bool> cards(52, false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char suit; int rank;
        cin >> suit >> rank;
        rank--;
        int order = suits.find(suit);
        cards[order * 13 + rank] = true;
    }
    for (int i = 0; i < 52; ++i) {
        if (cards[i]) continue;
        char suit = suits[i / 13];
        int rank = (i % 13) + 1;
        cout << suit << " " << rank << endl;
    }

    return 0;
}