//https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D

#include <bits/stdc++.h>

class EulerTour {
private:
    size_t N;
    std::vector<std::vector<size_t>> adj;

public:
    // Time: O(V)
    EulerTour(size_t const N = 0): N(N), adj(N) {}
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N)
    // Time: O(1)
    void add_edge(size_t const u, size_t const v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // r = [0,N)
    // Time: O(E)
    void solve(size_t r, std::vector<size_t>& tour, std::vector<size_t>& tin, std::vector<size_t>& tout) const {
        if (r >= N) throw std::out_of_range("r");

        std::stack<std::pair<size_t,int>> S;
        std::vector<bool> visited(N, false);

        tour.clear();
        tin.assign(N, 2 * N);
        tout.assign(N, 2 * N);

        S.push({r,-1});
        while (S.size()) {
            size_t v = S.top().first;
            int& i = S.top().second;
            if (i < 0) {
                visited[v] = true;
                tour.push_back(v);
                tin[v] = tour.size() - 1;
            } else if (size_t(i) < adj[v].size()) {
                auto u = adj[v][i];
                if (!visited[u]) S.push({u,-1});
            } else {
                tour.push_back(v);
                tout[v] = tour.size() - 1;
                S.pop();
            }
            i++;
        }
    }
};

template <class T = long long>
class BinaryIndexedTree {
public:
    using F = std::function<T(const T&, const T&)>;

protected:
    int N;
    std::vector<T> bit;
    T id;
    F plus;
    F minus;

public:
    // O(N)
    BinaryIndexedTree(
        int n,
        T id = T(),
        F plus = std::plus<T>(),
        F minus = std::minus<T>()
    )
        : N(n+1)
        , bit(n+1, id)
        , id(id)
        , plus(plus)
        , minus(minus)
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N - 1;
    }
    // Sum of array[0..index)
    // O(logN)
    // index = [0,N]
    T sum(int index) {
        if (index < 0 || index > N) throw;
        T ans = id;
        for (; index > 0; index -= index & -index) {
            ans = plus(ans, bit[index]);
        }
        return ans;
    }
    // Sum of array[l, r)
    // O(logN)
    T sum(int l, int r) {
        if (l > r) throw;
        return minus(sum(r), sum(l));
    }
    // Add value to array[index]
    // O(logN)
    // index = [0,N)
    void add(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        for (++index; index < N; index += index & -index) {
            bit[index] = plus(bit[index], value);
        }
    }
    // Set value to array[index]
    // O(logN)
    // index = [0,N)
    void set(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        T new_value = minus(value, sum(index, index+1));
        add(index, new_value);
    }
};


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    
    cin >> N;
    EulerTour euler_tour(N);
    for (int i = 0; i < N; ++i) {
        int K, c;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> c;
            euler_tour.add_edge(i, c);
        }
    }

    vector<size_t> tour, tin, tout;
    euler_tour.solve(0, tour, tin, tout);
    BinaryIndexedTree<long long> bit(2*N);

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int v, w;
            cin >> v >> w;
            bit.add(tin[v], w);
            bit.add(tout[v], -w);
        } else if (t == 1) {
            int u;
            cin >> u;
            cout << bit.sum(tin[u]+1) << endl;
        } else throw;
    }

    return 0;
}