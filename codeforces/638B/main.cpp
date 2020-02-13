// https://codeforces.com/contest/638/problem/B

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N;
vector<string> frags;

bool valid(string s) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        int j = s[i] - 'a';
        if (cnt[j] > 0) return false;
        cnt[j]++;
    }
    return true;
}
bool try_concat(string a, string b, string &c) {
    int ai, bi;
    bool found = false;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] != b[j]) continue;
            ai = i, bi = j, found = true;
            break;
        }
    }
    if (!found) return false;
    
    int as, bs;
    bool ans = true;
    for (as = ai, bs = bi; as >= 0 && bs >= 0; as--, bs--) {
        ans &= a[as] == b[bs];
    }
    if (!ans) return false;
    string s = as < 0 ? b.substr(0, bi) : a.substr(0, ai);

    int ae, be;
    for (ae = ai, be = bi; ae < a.size() && be < b.size(); ae++, be++) {
        ans &= a[ae] == b[be];
    }
    if (!ans) return false;
    string e = ae == a.size() ? b.substr(bi) : a.substr(ai);

    c = s + e;
    return valid(c);
}

struct Gene {
    string s;
    int bits;
    Gene(string s): s(s) {
        bits = 0;
        for (int i = 0; i < s.size(); ++i) {
            bits |= 1 << (s[i] - 'a');
        }
    }
    bool has_same_letter(const Gene& gene) {
        return (bits & gene.bits) > 0;
    }
};
bool operator<(const Gene& lhs, const Gene& rhs) {
    return lhs.s < rhs.s;
}

string solve() {
    set<Gene> genes;

    for (int i = 0; i < N; ++i) {
        genes.insert(Gene(frags[i]));
    }
    while (true) {
        bool found = false;
        Gene ga(""), gb("");
        for (auto a : genes) {
            for (auto b : genes) {
                if (a.s == b.s) continue;
                if (a.has_same_letter(b)) {
                    found = true;
                    ga = a, gb = b;
                    break;
                }
            }
        }
        if (!found) {
            break;
        }
        string c;
        if (!try_concat(ga.s, gb.s, c)) {
            // No answer
            return "";
        }
        genes.erase(ga); genes.erase(gb);
        genes.insert(Gene(c));
    }

    string ans = "";
    for (auto g : genes) {
        ans += g.s;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    frags.assign(N, string());
    for (int i = 0; i < N; ++i) {
        cin >> frags[i];
    }
    cout << solve() << endl;

    return 0;
}