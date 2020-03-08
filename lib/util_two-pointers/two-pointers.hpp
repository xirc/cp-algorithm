#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_A

template <class T>
class TwoPointers {
protected:
    int N;
    virtual T id() = 0;
    // O(K), [l,r)
    virtual bool satisfy() = 0;
    // O(K), [l,r)
    virtual void move_left(int l, int r) = 0;
    // O(K), [l,r)
    virtual void move_right(int l, int r) = 0;
    // O(K), [l,r)
    virtual void update(T& ans, int l, int r) = 0;
public:
    TwoPointers(int n): N(n) {}
    // O(KN)
    T solve() {
        T ans = id();
        int r = 0;
        for (int l = 0; l < N; l++) {
            while (r < l) r++;
            while (r < N && !satisfy()) {
                move_right(l, r);
                r++;
            }
            if (satisfy()) {
                update(ans, l, r);
            }
            move_left(l, r);
        }
        return ans;
    }
};