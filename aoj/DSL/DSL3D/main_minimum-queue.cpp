// https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D

#include <bits/stdc++.h>

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

template <class T, class Less = std::less<T>>
class MinMaxQueue {
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
    // Time: O(1)
    T maximum() const {
        if (in_stack.empty()) {
            return out_stack.maximum();
        } else if (out_stack.empty()) {
            return in_stack.maximum();
        } else {
            auto m1 = in_stack.maximum(), m2 = out_stack.maximum();
            return less(m1, m2) ? m2 : m1;
        }
    }
};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L;
    cin >> N >> L;
    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    MinMaxQueue<int> Q;
    for (int i = 0; i < L; ++i) {
        Q.push(array[i]);
    }
    cout << Q.minimum();
    for (int i = L; i < N; ++i) {
        Q.pop();
        Q.push(array[i]);
        cout << " " << Q.minimum();
    }
    cout << endl;

    return 0;
}