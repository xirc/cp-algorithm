#include <bits/stdc++.h>

using namespace std;

template <class T>
int partition(vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);
    return i;
}

template <class T>
void quick_sort(vector<T>& A, int p, int r) {
    if (p >= r) return;
    int q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
}

struct Card {
    char suit;
    int value;
    bool operator<(const Card& other) const {
        return value < other.value;
    }
    bool operator<=(const Card& other) const {
        return value <= other.value;
    }
};

// O(N logN)
bool is_stable(const vector<Card>& sorted, const vector<Card>& original) {
    auto stable_sorted = original;
    stable_sort(stable_sorted.begin(), stable_sorted.end());
    for (int i = 0; i < sorted.size(); ++i) {
        auto& u = sorted[i];
        auto& v = stable_sorted[i];
        if (u.suit != v.suit) return false;
        if (u.value != v.value) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<Card> cards;
    for (int i = 0; i < N; ++i) {
        char suit; int value;
        cin >> suit >> value;
        cards.push_back({ suit, value });
    }

    vector<Card> sorted = cards;
    quick_sort(sorted, 0, N-1);
    bool stable = is_stable(sorted, cards);

    cout << (stable ? "Stable" : "Not stable") << endl;
    for (auto& card : sorted) {
        cout << card.suit << " " << card.value << endl;
    }

    return 0;
}