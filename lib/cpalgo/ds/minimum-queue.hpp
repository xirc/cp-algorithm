#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <stack>
#include <algorithm>
#include "minimum-stack.hpp"

// MinimumQueue
// Memory: O(N)
template <class T>
class MinimumQueue {
protected:
    MinimumStack<T> Sp, Sr;

public:
    // O(1)
    bool empty() {
        return Sp.empty() && Sr.empty();
    }
    // O(1)
    void push_back(T value) {
        Sp.push(value);
    }
    // O(N)
    void pop_front() {
        transfer_if_needed();
        Sr.pop();
    }
    // O(N)
    T front() {
        transfer_if_needed();
        return Sr.top();
    }
    // O(1)
    T back() {
        if (!Sp.empty()) {
            return Sp.top();
        }
        return Sr.bottom();
    }
    // O(1)
    T minimum() {
        if (Sp.empty() || Sr.empty()) {
            return Sp.empty() ? Sr.minimum() : Sp.minimum();
        } else {
            return std::min(Sp.minimum(), Sr.minimum());
        }
    }

protected:
    // O(N)
    void transfer_if_needed() {
        if (!Sr.empty()) return;
        while (!Sp.empty()) {
            T value = Sp.top();
            Sp.pop();
            Sr.push(value);
        }
    }
};