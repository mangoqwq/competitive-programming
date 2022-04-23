#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Point{
    ll x, y; 
};
ll cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
ll cross(Point a, Point b, Point c){
    return cross({b.x - a.x, b.y - a.y}, {c.x - b.x, c.y - b.y});
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<Point> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i].x >> a[i].y;
    ll area = 0;
    for (int i = 0; i < N; ++i){
        area += cross(a[i], a[(i + 1) % N]);
    }
    cout << abs(area) << '\n';
}
