#pragma once

#include <algorithm>
#include <deque>
#include <functional>


// MinMaxStack
//
// Space: O(N)
//
// Verified
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D
//
template <class T, class Less = std::less<T>>
class MinMaxStack {
private:
    struct entry {
        T value;
        T minimum;
        T maximum;
    };
    std::deque<entry> S;
    Less less;

public:
    // Time: O(1)
    bool empty() const {
        return S.empty();
    }
    // Time: O(1)
    size_t size() const {
        return S.size();
    }
    // Time: O(1)
    void push(T const& value) {
        if (S.empty()) {
            S.push_back({ value, value, value });
        } else {
            auto e = S.back();
            auto new_min = less(value, e.minimum) ? value : e.minimum;
            auto new_max = less(e.maximum, value) ? value : e.maximum;
            S.push_back({ value, new_min, new_max });
        }
    }
    // Time: O(1)
    void pop() {
        S.pop_back();
    }
    // Time: O(1)
    T top() const {
        return S.back().value;
    }
    // Time: O(1)
    T bottom() const {
        return S.front().value;
    }
    // Time: O(1)
    T minimum() const {
        return S.back().minimum;
    }
    // Time: O(1)
    T maximum() const {
        return S.back().maximum;
    }
};