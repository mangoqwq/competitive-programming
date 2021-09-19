#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 0;

struct Point{
    ll x, y;
    void swp(){ swap(x, y); }
    bool operator<(const Point &rhs) const{
        return tie(x, y) < tie(rhs.x, rhs.y);
    }
};
set<Point> tmp;
set<Point> pts;
map<Point, vector<Point>> mp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    ll k; cin >> k;
    Point cur = {0, 0};
    tmp.insert(cur);
    for (char c : s){
        if (c == 'L') cur.x--;
        if (c == 'R') cur.x++;
        if (c == 'U') cur.y--;
        if (c == 'D') cur.y++;
        tmp.insert(cur);
    }
    for (auto a : tmp){
        ll x = a.x;
        ll y = a.y;
        if (cur.x < 0) x *= -1;
        if (cur.y < 0) y *= -1;
        if (cur.x == 0) swap(x, y);
        pts.insert({x, y});
    }
    if (cur.x == 0) cur.swp();
    cur.x = abs(cur.x); cur.y = abs(cur.y);
    if (cur.x == 0){
        cout << pts.size() << '\n';
        return 0;
    }
    for (auto [x, y] : pts){
        ll big = 2e5;
        ll q = (x + big * cur.x) / cur.x - big;
        ll cx = x - q * cur.x;
        ll cy = y - q * cur.y;
        mp[{cx, cy}].push_back({x, y});
    }

    ll ans = 0;
    for (auto [_, vec] : mp){
        vec.push_back({inf, inf});
        for (int i = 0; i < vec.size() - 1; ++i){
            ans += min(k, (vec[i + 1].x - vec[i].x) / cur.x);
        }
    }
    cout << ans << '\n';
}
