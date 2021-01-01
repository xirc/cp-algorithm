#pragma once

#include <algorithm>
#include <deque>
#include <functional>


// MinimumStack
//
// Space: O(N)
//
// Verified
//  - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
//
template <class T, class Less = std::less<T>>
class MinimumStack {
private:
    struct entry {
        T value;
        T minimum;
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
        T new_min =
            (S.empty() || less(value, S.back().minimum)) ? value : S.back().minimum;
        S.push_back({ value, new_min });
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
};