#pragma once

#include <deque>
#include <algorithm>

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

// MinimumStack
// Memory: O(N)
template <class T>
class MinimumStack {
protected:
    struct entry { T value, minimum; };
    std::deque<entry> S;
public:
    // O(1)
    bool empty() {
        return S.empty();
    }
    // O(1)
    void push(T value) {
        T new_min = S.empty() ? value : std::min(value, S.back().minimum);
        S.push_back({value, new_min});
    }
    // O(1)
    void pop() {
        S.pop_back();
    }
    // O(1)
    T top() {
        return S.back().value;
    }
    T bottom() {
        return S.front().value;
    }
    // O(1)
    T minimum() {
        return S.back().minimum;
    }
};