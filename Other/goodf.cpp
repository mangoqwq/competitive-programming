#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
const double eps = 1e-9;

struct Point{
    double x, y; ll id, val;
    double dir, abs_sq;
    Point() = default;
    Point(int _x, int _y, ll _id, ll _val) : x(_x), y(_y), id(_id), val(_val){
        dir = atan2(y, x);
        abs_sq = x * x + y * y;
    }
    bool operator<(const Point &r) const{
        if (abs(dir - r.dir) < eps) return abs_sq < r.abs_sq;
        else return dir < r.dir;
    }
} a[MN];
ll ans[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q, X, Y; cin >> N >> Q >> X >> Y;
    for (int i = 1; i <= N; ++i){
        int x, y, v; cin >> x >> y >> v;
        x -= X, y -= Y;
        a[i] = Point(x, y, i, v);
    }
    sort(a + 1, a + 1 + N);
    ll cur = 0; Point last = {0, 0, 0, 0};
    for (int i = 1; i <= N; ++i){
        if (abs(a[i].dir - last.dir) < eps) cur += a[i].val;
        else cur = a[i].val;
        ans[a[i].id] = cur;
        last = a[i];
    }
    while (Q--){
        int i; cin >> i;
        cout << ans[i] << '\n';
    }
}
