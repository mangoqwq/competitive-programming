#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        struct pt{ ll x, y; };
        auto sq = [&](ll x){ return x*x; };
        auto cross = [&](pt a, pt b, pt c){
            return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
        };
        auto ori = [&](pt a, pt b, pt c) -> int{
            ll val = cross(a, b, c);
            return (val == 0 ? 0 : (val < 0 ? -1 : 1));
        };
        auto dist = [&](pt a, pt b) -> ll{
            return sq(a.x-b.x) + sq(a.y-b.y);
        };

        vector<pt> v(N);
        for (int i = 0; i < N; ++i){
            cin >> v[i].x >> v[i].y;
        }
        sort(v.begin(), v.end(), [](pt a, pt b){
            return tie(a.x, a.y) < tie(b.x, b.y);
        });
        pt v0 = v[0];
        sort(v.begin(), v.end(), [&](pt a, pt b){
            int c = ori(v0, a, b);
            if (c == 0){
                return dist(v0, a) < dist(v0, b);
            }
            return c > 0;
        });
        vector<pt> hull = {v0};
        for (int i = 1; i < N; ++i){
            while (hull.size() >= 2 && ori(hull[hull.size()-2], hull.back(), v[i]) <= 0){
                hull.pop_back();
            }
            hull.push_back(v[i]);
        }
        ll ans = 0, besti = 0, bestj = 1;
        int T = hull.size(), p = 0;
        if (T == 2){
            cout << hull[besti].x << " " << hull[besti].y << " ";
            cout << hull[bestj].x << " " << hull[bestj].y << '\n';
            continue;
        }
        for (int i = 0; i < T; ++i){
            if (dist(hull[i], hull[p]) > ans){
                ans = dist(hull[i], hull[p]);
                besti = i, bestj = p;
            }
            while (cross(hull[p], hull[i], hull[(i+1)%T]) <= cross(hull[(p+1)%T], hull[i], hull[(i+1)%T])){
                p = (p+1)%T;
                if (dist(hull[i], hull[p]) > ans){
                    ans = dist(hull[i], hull[p]);
                    besti = i, bestj = p;
                }
            }
        }
        cout << hull[besti].x << " " << hull[besti].y << " ";
        cout << hull[bestj].x << " " << hull[bestj].y << '\n';
    }
}
