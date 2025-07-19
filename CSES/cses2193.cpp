#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    struct Point{ int x, y; };
 
    vector<Point> pts(N);
    for (int i = 0; i < N; ++i){
        cin >> pts[i].x >> pts[i].y;
    }
    pts.push_back(pts[0]);
 
    ll area = 0, boundary = 0;
    for (int i = 1; i <= N; ++i){
        area += 1LL * pts[i].y * pts[i - 1].x - 1LL * pts[i].x * pts[i - 1].y;
        int dx = pts[i].x - pts[i - 1].x;
        int dy = pts[i].y - pts[i - 1].y;
        boundary += abs(gcd(dx, dy));
    }
    area = abs(area) / 2;
 
    ll interior = area + 1 - boundary / 2;
    cout << interior << " " << boundary << '\n';
}
