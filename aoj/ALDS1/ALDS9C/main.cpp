#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
    vector<int> Q;
public:
    void push(int value) {
        int index = Q.size();
        Q.push_back(value);
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (Q[index] > Q[parent]) {
                swap(Q[index], Q[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    int top() {
        if (Q.empty()) throw;
        return Q[0];
    }
    void pop() {
        if (Q.empty()) throw;
        Q[0] = Q.back();
        Q.pop_back();
        const int N = Q.size();
        int index = 0;
        while (index < N) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int maxi = index;
            if (left < N && Q[left] > Q[maxi]) {
                maxi = left;
            }
            if (right < N && Q[right] > Q[maxi]) {
                maxi = right;
            }
            if (maxi != index) {
                swap(Q[index], Q[maxi]);
                index = maxi;
            } else {
                break;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    PriorityQueue queue;

    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "insert") {
            int value;
            cin >> value;
            queue.push(value);
        } else if (cmd == "extract") {
            int value = queue.top();
            queue.pop();
            cout << value << endl;
        } else if (cmd == "end") {
            break;
        } else throw;
    }

    return 0;
}