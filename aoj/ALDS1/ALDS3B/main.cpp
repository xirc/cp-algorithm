#include <bits/stdc++.h>

using namespace std;

struct proc {
    string name;
    int remaining_time;
};
struct proc_rec {
    string name;
    int timestamp;
};

vector<proc_rec> solve(const vector<proc>& processes, const int quantum) {
    int time = 0;
    vector<proc_rec> ans;
    queue<proc> Q;

    for (int i = 0; i < processes.size(); ++i) {
        Q.push(processes[i]);
    }

    while (Q.size()) {
        auto proc = Q.front(); Q.pop();
        int delta = min(proc.remaining_time, quantum);
        time += delta;
        proc.remaining_time -= delta;
        if (proc.remaining_time > 0) {
            Q.push(proc);
        } else {
            ans.push_back({ proc.name, time });
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<proc> processes(N);
    for (int i = 0; i < N; ++i) {
        cin >> processes[i].name >> processes[i].remaining_time;
    }

    auto ans = solve(processes, Q);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].name << " " << ans[i].timestamp << endl;
    }

    return 0;
}