#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Point{
    ll x, y; 
};
ll cross(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll val = cross({x1, y1}, {x2, y2}, {x3, y3});
        if (val == 0) cout << "TOUCH" << '\n';
        else cout << (val < 0 ? "RIGHT" : "LEFT") << '\n';
    }
}
