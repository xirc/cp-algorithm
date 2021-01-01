#pragma once

#include <algorithm>
#include <functional>
#include <stack>
#include "minimum_stack.hpp"


// MinimumQueue
//
// Space: O(N)
//
// Verified
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D
//
template <class T, class Less = std::less<T>>
class MinimumQueue {
private:
    MinimumStack<T, Less> Sp, Sr;
    Less less;

public:
    // Time: O(1)
    bool empty() const {
        return Sp.empty() && Sr.empty();
    }
    // Time: O(1)
    size_t size() const {
        return Sp.size() + Sr.size();
    }
    // Time: O(1)
    void push(T const& value) {
        Sp.push(value);
    }
    // Time: O(N), amortized O(1)
    void pop() {
        if (Sr.empty()) {
            while (!Sp.empty()) {
                auto value = Sp.top();
                Sp.pop();
                Sr.push(value);
            }
        }
        Sr.pop();
    }
    // Time: O(1)
    T front() const {
        if (Sr.empty()) {
            return Sp.bottom();
        }
        return Sr.top();
    }
    // Time: O(1)
    T back() const {
        if (!Sp.empty()) {
            return Sp.top();
        }
        return Sr.bottom();
    }
    // Time: O(1)
    T minimum() const {
        if (Sp.empty() || Sr.empty()) {
            return Sp.empty() ? Sr.minimum() : Sp.minimum();
        } else {
            auto m1 = Sp.minimum(), m2 = Sr.minimum();
            return less(m1, m2) ? m1 : m2;
        }
    }
};