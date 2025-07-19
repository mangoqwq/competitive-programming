#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    struct Point{ ll x, y; };
    auto cross = [](Point a, Point b, Point c){
        return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    };
    auto distsq = [](Point a, Point b){
        return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    };
    auto ori = [&](Point a, Point b, Point c){
        ll cp = cross(a, b, c);
        if (cp < 0) return -1;
        else if (cp == 0) return 0;
        else return 1;
    };
    auto convex_hull = [&](vector<Point> pts){
        Point p0 = *min_element(pts.begin(), pts.end(), [](Point a, Point b){
            return tie(a.x, a.y) < tie(b.x, b.y);
        });
        sort(pts.begin(), pts.end(), [&](Point a, Point b){
            int o = ori(p0, a, b);
            if (o == 0) return distsq(p0, a) < distsq(p0, b);
            else return o > 0;
        });
        int i = pts.size() - 1;
        while (ori(p0, pts[i], pts.back()) == 0) i--;
        reverse(pts.begin() + i + 1, pts.end());
 
        vector<Point> hull;
        for (Point p : pts){
            while (hull.size() >= 2 && ori(hull[hull.size() - 2], hull.back(), p) == -1) hull.pop_back();
            hull.push_back(p);
        }
        return hull;
    };
 
    vector<Point> vec(N);
    for (int i = 0; i < N; ++i){
        cin >> vec[i].x >> vec[i].y;
    }
    vector<Point> hull = convex_hull(vec);
    cout << hull.size() << '\n';
    for (Point p : hull){
        cout << p.x << " " << p.y << '\n';
    }
}
