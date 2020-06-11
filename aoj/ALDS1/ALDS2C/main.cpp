#include <bits/stdc++.h>

using namespace std;

template<class T> 
void bubble_sort(vector<T>& array) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = array.size() - 1; j > i; --j) {
            if (array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}

template<class T>
void selection_sort(vector<T>& array) {
    for (int i = 0; i < array.size(); ++i) {
        int mini = i;
        for (int j = i; j < array.size(); ++j) {
            if (array[j] < array[mini]) {
                mini = j;
            }
        }
        swap(array[i], array[mini]);
    }
}

struct Card {
    string raw; // '[SHCD][1-9]'
    int suit; // 0 to 3
    int value; // 0 to 8
    int to_code() const {
        return suit * 9 + value;
    }
    static Card from_raw(const string& raw) {
        const string suits = "SHCD";
        const string numbers = "123456789";
        auto suit = suits.find(raw[0]);
        auto value = numbers.find(raw[1]);
        if (suit == string::npos) throw;
        if (value == string::npos) throw;
        return { raw, (int)suit, (int)value };
    }
};
bool operator<(const Card& lhs, const Card& rhs) {
    return lhs.value < rhs.value;
}

array<int,36> encode(const vector<Card>& cards) {
    array<int,9> counter = { 0 };
    array<int,36> code = { 0 };
    for (auto card : cards) {
        code[card.to_code()] = ++counter[card.value];
    }
    return code;
}

bool is_stable(const vector<Card>& original, const vector<Card>& sorted) {
    auto orig_code = encode(original);
    auto sorted_code = encode(sorted);
    if (orig_code.size() != sorted_code.size()) return false;
    for (int i = 0; i < orig_code.size(); ++i) {
        if (orig_code[i] != sorted_code[i]) return false;
    }
    return true;
}

void dump(const vector<Card>& cards) {
    for (int i = 0; i < cards.size(); ++i) {
        if (i > 0) cout << " ";
        cout << cards[i].raw;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<Card> cards(N);
    for (int i = 0; i < N; ++i) {
        string raw;
        cin >> raw;
        cards[i] = Card::from_raw(raw);
    }

    auto bubble_sorted = cards;
    bubble_sort(bubble_sorted);
    auto is_stable_bubble = is_stable(cards, bubble_sorted);

    auto selection_sorted = cards;
    selection_sort(selection_sorted);
    auto is_stable_selection = is_stable(cards, selection_sorted);

    dump(bubble_sorted);
    cout << (is_stable_bubble ? "Stable" : "Not stable") << endl;
    dump(selection_sorted);
    cout << (is_stable_selection ? "Stable" : "Not stable") << endl;

    return 0;
}