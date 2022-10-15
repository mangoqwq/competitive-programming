#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

struct Point{
    double x, y;
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
    bool operator==(const Point &a) const{
        return x==a.x&&y==a.y;
    }
};
double cross(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
double dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double ldist(Point l1, Point l2, Point p){
    return abs(cross(l1,l2,p))/dist(l1,l2);
}
double proj(Point l1, Point l2, Point p){
    return ((l2.x-l1.x)*(p.x-l2.x)+(l2.y-l1.y)*(p.y-l2.y))/dist(l1,l2);
}

void convex_hull(vector<Point> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    Point p1=v[0], p2=v.back();
    vector<Point> lo={p1}, hi={p1};
    for (int i=1;i<v.size();++i){
        if (i==v.size()-1||cross(p1,v[i],p2)<0){
            while (hi.size()>=2&&cross(hi[hi.size()-2],hi[hi.size()-1],v[i])>=0) hi.pop_back();
            hi.push_back(v[i]);
        }
        if (i==v.size()-1||cross(p1,v[i],p2)>0){
            while (lo.size()>=2&&cross(lo[lo.size()-2],lo[lo.size()-1],v[i])<=0) lo.pop_back();
            lo.push_back(v[i]);
        }
    }
    v.clear();
    for (int i=0;i<hi.size();++i) v.push_back(hi[i]);
    for (int i=lo.size()-2;i>0;--i) v.push_back(lo[i]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Point> v(n);
    for (auto &[x,y]:v) cin >> x >> y;
    convex_hull(v);
    n=v.size();
    int pl=0, pm=0, pr=0;
    for (int i=0;i<n;++i){
        if (proj(v[n-1],v[0],v[i])>=proj(v[n-1],v[0],v[pl])) pl=i;
        if (ldist(v[n-1],v[0],v[i])>=ldist(v[n-1],v[0],v[pm])) pm=i;
        if (proj(v[0],v[n-1],v[i])>=proj(v[0],v[n-1],v[pr])) pr=i;
    }
    double ans=(proj(v[n-1],v[0],v[pl])+dist(v[n-1],v[0])+proj(v[0],v[n-1],v[pr]))*ldist(v[n-1],v[0],v[pm]);
    for (int i=1;i<n;++i){
        while (proj(v[i-1],v[i],v[(pl+1)%n])>=proj(v[i-1],v[i],v[pl])) pl=(pl+1)%n;
        while (ldist(v[i-1],v[i],v[(pm+1)%n])>=ldist(v[i-1],v[i],v[pm])) pm=(pm+1)%n;
        while (proj(v[i],v[i-1],v[(pr+1)%n])>=proj(v[i],v[i-1],v[pr])) pr=(pr+1)%n;
        ans=min(ans,(proj(v[i-1],v[i],v[pl])+dist(v[i-1],v[i])+proj(v[i],v[i-1],v[pr]))*ldist(v[i-1],v[i],v[pm]));
    }
    cout << fixed << setprecision(0) << ans << '\n';
}