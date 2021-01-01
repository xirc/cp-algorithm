// https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D

#include <bits/stdc++.h>

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

    MinimumQueue<int> Q;
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