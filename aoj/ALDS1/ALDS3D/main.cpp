#include <bits/stdc++.h>

using namespace std;

struct flood {
    int x;
    int value;
};

vector<flood> solve(string land_repr) {
    int x = 0;
    stack<int> xs;
    stack<flood> floods;

    for (char c : land_repr) {
        if (c == '\\') {
            xs.push(x);
        } else if (c == '/') {
            if (xs.size() > 0) {
                auto lx = xs.top(); xs.pop();
                int value = x - lx;
                floods.push({ lx, value });
            }
        } else if (c == '_') {
            // Do nothing
        } else throw;
        x++;
    }

    vector<flood> ans;
    if (floods.empty()) {
        return ans;
    }
    auto cur = floods.top(); floods.pop();
    while (floods.size()) {
        auto f = floods.top(); floods.pop();
        if (f.x > cur.x) {
            cur.value += f.value;
        } else {
            ans.push_back(cur);
            cur = f;
        }
    }
    ans.push_back(cur);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string land;
    cin >> land;

    auto floods = solve(land);
    int total = 0;
    for (auto f : floods) {
        total += f.value;
    }
    
    cout << total << endl;
    cout << floods.size();
    for (auto f : floods) {
        cout << " " << f.value;
    }
    cout << endl;

    return 0;
}