#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 8;
string s[MN];
struct Point{ int x, y; };
vector<Point> queens;
bool attack(Point a, Point b){
    return a.x == b.x || a.y == b.y || a.x + a.y == b.x + b.y || a.x - a.y == b.x - b.y;
}

int ans = 0;

void solve(int i){
    if (i == 8){ ans++; queens.pop_back(); return; }
    for (int j = 0; j < 8; ++j){
        if (s[i][j] == '*') continue;
        Point cur = {i, j};
        bool can = 1;
        for (Point p : queens) can &= !attack(cur, p);
        if (can){
            queens.push_back(cur);
            solve(i + 1);
        }
    }
    queens.pop_back();
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 8; ++i) cin >> s[i];
    solve(0);
    cout << ans << '\n';
}
