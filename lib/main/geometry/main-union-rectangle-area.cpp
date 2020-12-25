#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/geometry/union-rectangle-area.hpp"

using namespace std;

using vector2 = complex<double>;

vector<array<vector2,2>> rectangles;

void action_init() {
    rectangles.clear();
}

void action_rect() {
    double lx, ly, ux, uy;
    cin >> lx >> ly >> ux >> uy;
    if (lx > ux) swap(lx, ux);
    if (ly > uy) swap(ly, uy);
    rectangles.push_back({ vector2(lx, ly), vector2(ux, uy) });
}

void action_solve() {
    double ans = union_rectangle_area(rectangles);
    cout << ans << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Area of Union Rectangles";
    commands["init"] = { "init", action_init };
    commands["rect"] = { "rect {lx} {ly} {ux} {uy}", action_rect };
    commands["solve"] = { "solve", action_solve };
}