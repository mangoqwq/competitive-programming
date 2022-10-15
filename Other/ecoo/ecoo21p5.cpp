#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;
const ll lim=2*inf;
const ll infll=0x3f3f3f3f3f3f3f3f;

struct Point{
    ll x, y;
    bool operator==(const Point &a) const{
        return x==a.x&&y==a.y;
    }
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
}; set<Point> ans;
struct Line{
    ll x, y, dx, dy;
    Point nxt(){
        long double fdx=dx/2.0, fdy=dy/2.0;
        long double fx=x+0.0, fy=y+0.0;
        fx+=fdx, fy+=fdy;
        long double ndx=-fdy, ndy=fdx;
        fx+=ndx*lim, fy+=ndy*lim;
        return {(ll)fx,(ll)fy};
    }
};

Point Query(Point p){
    ll rx, ry;
    cout << "? " << p.x << " " << p.y << '\n';
    cout.flush();
    cin >> rx >> ry;
    if (rx==1e9+1&&ry==1e9+1) exit(0);
    return {rx,ry};
}

void divide(Point a, Point b){
    Line l={a.x,a.y,b.x-a.x,b.y-a.y};
    Point c=Query(l.nxt());
    if (c==a||c==b) return;
    ans.insert(c);
    divide(a,c); divide(c,b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<Point> tmp;
    ll infl=-infll, infr=-infll;
    while (tmp.size()<2){
        Point a=Query({infl,infr});
        if (tmp.empty()||!(a==tmp.back())) tmp.push_back(a);
        swap(infl,infr), infl=-infl;
    }
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    ans.insert(tmp[0]); ans.insert(tmp[1]);
    divide(tmp[0],tmp[1]), divide(tmp[1],tmp[0]);
    cout << "! " << ans.size() << '\n';
}