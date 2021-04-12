#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=10001;

struct Point{
    int x, y;
    bool operator<(const Point &a) const {
        return tie(x,y)<tie(a.x,a.y);
    }
}; vector<Point> trees;

int cross(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
}

void build(vector<Point> &v){
    sort(v.begin(),v.end());
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
    for (int i=1;i<=n;++i){
        int x, y; cin >> x >> y;
        trees.push_back({x,y});
    }
    build(trees);
    int area=0;
    for (int i=2;i<trees.size();++i){
        area+=cross(trees[0],trees[i-1],trees[i]);
    }
    cout << abs(area)/100 << '\n';
}