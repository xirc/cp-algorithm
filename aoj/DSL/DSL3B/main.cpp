// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_B

template <class T>
class TwoPointers {
protected:
    int N;
    virtual T id() = 0;
    // O(K), [l,r)
    virtual bool should_move_right(int l, int r) = 0;
    // O(K), [l,r)
    virtual void move_left(int l, int r) = 0;
    // O(K), [l,r)
    virtual void move_right(int l, int r) = 0;
    // O(K), [l,r)
    virtual void update(T& ans, int l, int r) = 0;
public:
    TwoPointers(int n): N(n) {}
    // O(KN)
    T solve() {
        T ans = id();
        int r = 0;
        for (int l = 0; l < N; ++l) {
            while (r < l) {
                move_right(l, r);
                ++r;
            }
            while (r < N && should_move_right(l,r)) {
                move_right(l, r);
                ++r;
            }
            update(ans, l, r);
            move_left(l, r);
        }
        return ans;
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solver : public TwoPointers<int> {
    vector<int> array;
    vector<int> unique;
    int K;
    int count;

public:
    Solver(const vector<int>& array, int K)
        : TwoPointers(array.size())
        , array(array), unique(K,0), K(K), count(0) {}

protected:
    int id() override {
        return N + 1;
    }
    bool should_move_right(int l, int r) override {
        return count < K;
    }
    void move_left(int l, int r) override {
        int index = array[l] - 1;
        if (index >= K) return;
        unique[index]--;
        if (unique[index] == 0) --count;
    }
    void move_right(int l, int r) override {
        int index = array[r] - 1;
        if (index >= K) return;
        unique[index]++;
        if (unique[index] == 1) ++count;
    }
    void update(int& ans, int l, int r) override {
        if (count == K) {
            ans = min(ans, r - l);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> A;

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Solver solver(A, K);
    int ans = solver.solve();
    if (ans == N + 1) ans = 0;
    cout << ans << endl;

    return 0;
}