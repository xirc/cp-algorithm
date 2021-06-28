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
    MinMaxStack<T, Less> in_stack, out_stack;
    Less less;

public:
    // Time: O(1)
    bool empty() const {
        return in_stack.empty() && out_stack.empty();
    }
    // Time: O(1)
    size_t size() const {
        return in_stack.size() + out_stack.size();
    }
    // Time: O(1)
    void push(T const& value) {
        in_stack.push(value);
    }
    // Time: O(N), amortized O(1)
    void pop() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                auto value = in_stack.top();
                in_stack.pop();
                out_stack.push(value);
            }
        }
        out_stack.pop();
    }
    // Time: O(1)
    T front() const {
        if (out_stack.empty()) {
            return in_stack.bottom();
        }
        return out_stack.top();
    }
    // Time: O(1)
    T back() const {
        if (!in_stack.empty()) {
            return in_stack.top();
        }
        return out_stack.bottom();
    }
    // Time: O(1)
    T minimum() const {
        if (in_stack.empty()) {
            return out_stack.minimum();
        } else if (out_stack.empty()) {
            return in_stack.minimum();
        } else {
            auto m1 = in_stack.minimum(), m2 = out_stack.minimum();
            return less(m1, m2) ? m1 : m2;
        }
    }
};