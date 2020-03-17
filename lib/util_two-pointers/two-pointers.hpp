#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C

template <class T>
class TwoPointers {
protected:
    int N;
    virtual T id() = 0;
    // O(K), [l,r)
    virtual bool should_move_right(int l, int r) = 0;
    // O(K), [l,r)
    virtual void move_left(int l, int r) = 0;
    // O(K), [l,r)
    virtual void move_right(int l, int r) = 0;
    // O(K), [l,r)
    virtual void update(T& ans, int l, int r) = 0;
public:
    // O(1)
    TwoPointers(int n): N(n) {}
    // O(KN)
    T solve() {
        T ans = id();
        int r = 0;
        for (int l = 0; l < N; ++l) {
            while (r < l) {
                move_right(l, r);
                ++r;
            }
            while (r < N && should_move_right(l,r)) {
                move_right(l, r);
                ++r;
            }
            update(ans, l, r);
            move_left(l, r);
        }
        return ans;
    }
};