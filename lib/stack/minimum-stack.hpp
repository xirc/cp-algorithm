#pragma once

#include <stack>
#include <algorithm>

template <class T>
class MinimumStack {
    struct entry { T value, minimum; };
    std::stack<entry> S;
public:
    // O(1)
    bool empty() {
        return S.empty();
    }
    // O(1)
    void push(T value) {
        T new_min = S.empty() ? value : std::min(value, S.top().minimum);
        S.push({value, new_min});
    }
    // O(1)
    void pop() {
        S.pop();
    }
    // O(1)
    T top() {
        return S.top().value;
    }
    // O(1)
    T minimum() {
        return S.top().minimum;
    }
};