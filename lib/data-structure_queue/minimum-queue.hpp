#pragma once

#include <stack>
#include <algorithm>

template <class T>
class MinimumQueue {
    class MinimumStack {
        struct entry { T value, minimum; };
        std::deque<entry> S;
    public:
        bool empty() {
            return S.empty();
        }
        void push(T value) {
            T mini = S.empty() ? value : std::min(S.back().minimum, value);
            S.push_back({value, mini});
        }
        void pop() {
            S.pop_back();
        }
        T top() {
            return S.back().value;
        }
        T bottom() {
            return S.front().value;
        }
        T minimum() {
            return S.back().minimum;
        }
    };
    MinimumStack Sp, Sr;

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

private:
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