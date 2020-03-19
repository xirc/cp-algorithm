#pragma once

#include <utility>
#include <vector>
#include <algorithm>

// Mo's Algorithm
// Memory: Q + N
template <class T>
class Mo {
public:
    static const int S = 700; // Block Size
    struct Query {
        int l, r, idx;
        bool operator<(Query &rhs) {
            return std::make_pair(l / S, r) < std::make_pair(rhs.l / S, rhs.r);
        }
    };
    // O((N+Q)sqrt(N))
    std::vector<T> solve(std::vector<Query>& queries) {
        std::vector<T> ans(queries.size());
        std::sort(ans.begin(), ans.end());

        int cl = 0, cr = -1;
        for (auto query : queries) {
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