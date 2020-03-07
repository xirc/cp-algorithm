#pragma once

#include <vector>
#include <stack>

std::vector<int> construct(const std::vector<int>& ary) {
    const int N = ary.size();
    std::vector<int> parent(N, -1);
    std::stack<int> S;
    for (int i = 0; i < N; ++i) {
        int last = -1;
        while (!S.empty() && ary[S.top()] >= ary[i]) {
            last = S.top();
            S.pop();
        }
        if (!S.empty()) {
            parent[i] = S.top();
        }
        if (last != -1) {
            parent[last] = i;
        }
        S.push(i);
    }
    return parent;
}