// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C

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

using namespace std;

vector<int> A;

class Solver : public TwoPointers<long long> {
    long long X;
    long long sum;

public:
    Solver(int N, long long x) : TwoPointers(N), X(x), sum(0) {}

protected:
    long long id() override {
        return 0;
    }
    bool should_move_right(int l, int r) override {
        return sum + A[r] <= X;
    }
    void move_left(int l, int r) override {
        sum -= A[l];
    }
    void move_right(int l, int r) override {
        sum += A[r];
    }
    void update(long long& ans, int l, int r) override {
        ans += r - l;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; ++i) {
        long long x;
        cin >> x;
        Solver solver(N, x);
        cout << solver.solve() << endl;
    }

    return 0;
}