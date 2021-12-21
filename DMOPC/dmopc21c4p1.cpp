#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e3 + 1;

struct Point{ ll x, y; } tri[MN][3];
ll cross(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> tri[i][0].x >> tri[i][0].y;
        cin >> tri[i][1].x >> tri[i][1].y;
        cin >> tri[i][2].x >> tri[i][2].y;
    }
    while (Q--){
        int cnt = 0;
        Point cur; cin >> cur.x >> cur.y;
        for (int j = 1; j <= N; ++j){
            bool pos = 0, neg = 0;
            ll v1 = cross(tri[j][0], tri[j][1], cur);
            ll v2 = cross(tri[j][1], tri[j][2], cur);
            ll v3 = cross(tri[j][2], tri[j][0], cur);
            pos = (v1 > 0) || (v2 > 0) || (v3 > 0);
            neg = (v1 < 0) || (v2 < 0) || (v3 < 0);
            cnt += !(pos && neg);
        }
        cout << cnt << '\n';
    }
}
