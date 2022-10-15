#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt{
    ll x, y;
    pt operator-(const pt &o) const{
        return {(x-o.x), (y-o.y)};
    }
};

ll cross(pt a, pt b, pt c){
    return (b-a).x * (c-b).y - (b-a).y * (c-b).x;
}
ll ori(pt a, pt b, pt c){
    ll cr = cross(a, b, c);
    if (cr == 0) return 0;
    else return (cr < 0 ? -1 : 1);
}

bool ranint(int a, int b, int c, int d){
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    return max(a, c) <= min(b, d);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    pt a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    bool ans = 1;
    ans &= ranint(a.x, b.x, c.x, d.x);
    ans &= ranint(a.y, b.y, c.y, d.y);
    ans &= (ori(a, b, c) * ori(a, b, d) <= 0);
    ans &= (ori(c, d, a) * ori(c, d, b) <= 0);
    cout << ans << '\n';
}
