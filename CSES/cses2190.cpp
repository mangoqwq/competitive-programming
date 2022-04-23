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
ll ori(Point a, Point b, Point c){
    ll val = cross(a, b, c);
    if (val == 0) return 0;
    else return (val > 0 ? 1 : -1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point p1 = {x1, y1};
        Point p2 = {x2, y2};
        Point p3 = {x3, y3};
        Point p4 = {x4, y4};
        if ((!ori(p1, p2, p3) && p3.x >= min(p1.x, p2.x) && p3.x <= max(p1.x, p2.x) && p3.y >= min(p1.y, p2.y) && p3.y <= max(p1.y, p2.y)) ||
            (!ori(p1, p2, p4) && p4.x >= min(p1.x, p2.x) && p4.x <= max(p1.x, p2.x) && p4.y >= min(p1.y, p2.y) && p4.y <= max(p1.y, p2.y)) ||
            (!ori(p3, p4, p1) && p1.x >= min(p3.x, p4.x) && p1.x <= max(p3.x, p4.x) && p1.y >= min(p3.y, p4.y) && p1.y <= max(p3.y, p4.y)) ||
            (!ori(p3, p4, p2) && p2.x >= min(p3.x, p4.x) && p2.x <= max(p3.x, p4.x) && p2.y >= min(p3.y, p4.y) && p2.y <= max(p3.y, p4.y))){
            cout << "YES" << '\n';
        }
        else if (ori(p1, p2, p3) != ori(p1, p2, p4) && ori(p3, p4, p1) != ori(p3, p4, p2)){
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
}
