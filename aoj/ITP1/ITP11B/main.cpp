#include <bits/stdc++.h>

// Dice
// on Left-Handed System
template <class T = int>
class Dice {
public:
    enum Face {
        TOP = 0, BOTTOM = 1,
        FRONT = 2, BACK = 3,
        LEFT = 4, RIGHT = 5,
    };
    Dice() {
        id[TOP] = 0;
        id[FRONT] = 1;
        id[LEFT] = 2;
        id[RIGHT] = 3;
        id[BACK] = 4;
        id[BOTTOM] = 5;
    }
    // O(1)
    T& operator[](Face face) { return value[id[face]]; }
    // O(1)
    const T& operator[](Face face) const { return value[id[face]]; }
    // O(1)
    bool operator==(const Dice<T>& other) const {
        const auto &self = *this;
        return self[TOP] = other[TOP] && self[BOTTOM] == other[BOTTOM] &&
            self[FRONT] == other[FRONT] && self[BACK] == other[BACK] &&
            self[LEFT] == other[LEFT] && self[RIGHT] == other[RIGHT];
    }
    // Roll left around the x axis
    // O(1)
    void roll_lx() {
        roll(TOP, FRONT, BOTTOM, BACK);
    }
    // Roll right around the x axis
    // O(1)
    void roll_rx() {
        roll(TOP, BACK, BOTTOM, FRONT);
    }
    // Roll left around the y axis
    // O(1)
    void roll_ly() {
        roll(FRONT, RIGHT, BACK, LEFT);
    }
    // Roll right around the y axis
    // O(1)
    void roll_ry() {
        roll(FRONT, LEFT, BACK, RIGHT);
    }
    // Roll left around the z axis
    // O(1)
    void roll_lz() {
        roll(TOP, RIGHT, BOTTOM, LEFT);
    }
    // Roll right around the z axis
    // O(1)
    void roll_rz() {
        roll(TOP, LEFT, BOTTOM, RIGHT);
    }
    // Enumerate all dice roll patterns.
    // O(1)
    std::vector<Dice> all() const {
        Dice dice = *this;
        std::vector<Dice> ans;
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < 4; ++i) {
                ans.push_back(dice);
                dice.roll_ly();
            }
            if (k & 1) {
                dice.roll_lx();
            } else {
                dice.roll_lz();
            }
        }
        return ans;
    }

private:
    T value[6];
    int id[6];
    // O(1)
    void roll(Face a, Face b, Face c, Face d) {
        T tmp = id[a];
        id[a] = id[b];
        id[b] = id[c];
        id[c] = id[d];
        id[d] = tmp;
    }
};


using namespace std;

using DiceT = Dice<int>;
DiceT dice;

int solve(int top, int front) {
    for (auto p : dice.all()) {
        if (p[DiceT::TOP] != top) continue;
        if (p[DiceT::FRONT] != front) continue;
        return p[DiceT::RIGHT];
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> dice[DiceT::TOP];
    cin >> dice[DiceT::FRONT];
    cin >> dice[DiceT::RIGHT];
    cin >> dice[DiceT::LEFT];
    cin >> dice[DiceT::BACK];
    cin >> dice[DiceT::BOTTOM];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int top, front;
        cin >> top >> front;
        cout << solve(top, front) << endl;
    }

    return 0;
}