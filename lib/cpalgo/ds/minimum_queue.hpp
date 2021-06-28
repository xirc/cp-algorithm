#pragma once

#include <algorithm>
#include <functional>
#include <stack>
#include "minmax_stack.hpp"


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
    MinMaxStack<T, Less> in_stack, Sr;
    Less less;

public:
    // Time: O(1)
    bool empty() const {
        return in_stack.empty() && Sr.empty();
    }
    // Time: O(1)
    size_t size() const {
        return in_stack.size() + Sr.size();
    }
    // Time: O(1)
    void push(T const& value) {
        in_stack.push(value);
    }
    // Time: O(N), amortized O(1)
    void pop() {
        if (Sr.empty()) {
            while (!in_stack.empty()) {
                auto value = in_stack.top();
                in_stack.pop();
                Sr.push(value);
            }
        }
        Sr.pop();
    }
    // Time: O(1)
    T front() const {
        if (Sr.empty()) {
            return in_stack.bottom();
        }
        return Sr.top();
    }
    // Time: O(1)
    T back() const {
        if (!in_stack.empty()) {
            return in_stack.top();
        }
        return Sr.bottom();
    }
    // Time: O(1)
    T minimum() const {
        if (in_stack.empty() || Sr.empty()) {
            return in_stack.empty() ? Sr.minimum() : in_stack.minimum();
        } else {
            auto m1 = in_stack.minimum(), m2 = Sr.minimum();
            return less(m1, m2) ? m1 : m2;
        }
    }
};