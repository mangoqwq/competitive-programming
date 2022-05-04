#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    struct Point{ ll x, y; };
    auto cmpxy = [](Point a, Point b){
        return tie(a.x, a.y) < tie(b.x, b.y);
    };
    auto cmpy = [](Point a, Point b){
        return a.y < b.y;
    };
    auto distsq = [](Point a, Point b){
        return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    };
 
    int N; cin >> N;
    vector<Point> pts(N);
    for (int i = 0; i < N; ++i){
        cin >> pts[i].x >> pts[i].y;
    }
    sort(pts.begin(), pts.end(), cmpxy);
 
    function<ll(vector<Point>&)> mn_dist = [&](vector<Point> &pts){
 
        ll ret = 9e18;
        int n = pts.size();
 
        if (pts.size() <= 2){
            for (int i = 0; i < n; ++i){
                for (int j = i + 1; j < n; ++j){
                    ret = min(ret, distsq(pts[i], pts[j]));
                }
            }
            sort(pts.begin(), pts.end(), cmpy);
            return ret;
        }
 
        vector<Point> lef, rig;
        int cenx = pts[n / 2].x;
        for (int i = 0; i <= n / 2; ++i) lef.push_back(pts[i]);
        for (int i = n / 2 + 1; i < n; ++i) rig.push_back(pts[i]);
 
        ret = min(mn_dist(lef), mn_dist(rig));
        merge(lef.begin(), lef.end(), rig.begin(), rig.end(), pts.begin(), cmpy);
        
        vector<Point> check;
        for (int i = 0; i < n; ++i){
            if (abs(pts[i].x - cenx) <= ret){
                check.push_back(pts[i]);
            }
        }
 
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if ((pts[j].y - pts[i].y) * (pts[j].y - pts[i].y) > ret) break;
                ret = min(ret, distsq(pts[j], pts[i]));
            }
        }
        return ret;
    };
    cout << mn_dist(pts) << '\n';
}
