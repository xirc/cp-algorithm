// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <bits/stdc++.h>

// MinimumStack
// Memory: O(N)
template <class T>
class MinimumStack {
protected:
    struct entry { T value, minimum; };
    std::deque<entry> S;
public:
    // O(1)
    bool empty() {
        return S.empty();
    }
    // O(1)
    void push(T value) {
        T new_min = S.empty() ? value : std::min(value, S.back().minimum);
        S.push_back({value, new_min});
    }
    // O(1)
    void pop() {
        S.pop_back();
    }
    // O(1)
    T top() {
        return S.back().value;
    }
    T bottom() {
        return S.front().value;
    }
    // O(1)
    T minimum() {
        return S.back().minimum;
    }
};

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
        Q.push_back(array[i]);
    }
    cout << Q.minimum();
    for (int i = L; i < N; ++i) {
        Q.pop_front();
        Q.push_back(array[i]);
        cout << " " << Q.minimum();
    }
    cout << endl;

    return 0;
}