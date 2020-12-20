#pragma once

#include <vector>
#include <algorithm>
#include <tuple>

// Mo's Algorithm
// Memory: Q + N
template <class T>
class Mo {
    // use 'const' for compiler's optimization
    // S = sqrt(N) or sqrt(Q)
    static const int S = 700;
    struct Query {
        int l, r, idx;
        bool operator<(Query &other) {
            return std::make_pair(l / S, r) < std::make_pair(other.l / S, other.r);
        }
    };

public:
    // O((N+Q)sqrt(N)) if S = sqrt(N)
    // O(N sqrt(Q)) if S = sqrt(Q)
    std::vector<T> solve(std::vector<std::pair<int,int>>& queries) {
        std::vector<T> ans(queries.size());
        std::vector<Query> Q(queries.size());
        for (int i = 0; i < Q.size(); ++i) {
            int l, r;
            std::tie(l, r) = queries[i];
            Q[i] = { l, r, i };
        }
        std::sort(Q.begin(), Q.end());

        int cl = 0, cr = -1;
        for (auto query : Q) {
            while (cl > query.l){
                cl--;
                add(cl);
            }
            while (cr < query.r) {
                cr++;
                add(cr);
            }
            while (cl < query.l) {
                remove(cl);
                cl++;
            }
            while (cr > query.r) {
                remove(cr);
                cr--;
            }
            ans[query.idx] = answer();
        }
        return ans;
    }

protected:
    void remove(int idx);
    void add(int idx);
    T answer();
};