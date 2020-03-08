// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_B

template <class T>
class TwoPointers {
protected:
    int N;
    virtual T id() = 0;
    // O(K), [l,r)
    virtual bool satisfy() = 0;
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
        for (int l = 0; l < N; l++) {
            while (r < l) r++;
            while (r < N && !satisfy()) {
                move_right(l, r);
                r++;
            }
            if (satisfy()) {
                update(ans, l, r);
            }
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
    bool satisfy() override {
        return count == K;
    }
    void move_left(int left, int right) override {
        int index = array[left] - 1;
        if (index >= K) return;
        unique[index]--;
        if (unique[index] == 0) --count;
    }
    void move_right(int left, int right) override {
        int index = array[right] - 1;
        if (index >= K) return;
        unique[index]++;
        if (unique[index] == 1) ++count;
    }
    void update(int& ans, int left, int right) override {
        ans = min(ans, right - left);
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