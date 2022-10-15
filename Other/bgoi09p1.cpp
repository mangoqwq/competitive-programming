#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e4+1;
const double PI=3.14159265359;

struct Point{
    int x, y;
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
    bool operator==(const Point &a) const{
        return x==a.x&&y==a.y;
    }
};

int cross(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}

void build(vector<Point> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    Point p1=v[0], p2=v.back();
    vector<Point> up={p1}, bot={p1};
    for (int i=1;i<v.size();++i){
        if (i==v.size()-1||cross(p1,v[i],p2)<0){
            while (up.size()>=2&&cross(up[up.size()-2],up[up.size()-1],v[i])>=0) up.pop_back();
            up.push_back(v[i]);
        }
        if (i==v.size()-1||cross(p1,v[i],p2)>0){
            while (bot.size()>=2&&cross(bot[bot.size()-2],bot[bot.size()-1],v[i])<=0) bot.pop_back();
            bot.push_back(v[i]);
        }
    }
    v.clear();
    for (int i=0;i<up.size();++i) v.push_back(up[i]);
    for (int i=bot.size()-2;i>0;--i) v.push_back(bot[i]);
}

double dist(Point a, Point b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double angle(Point a, Point b, Point c){
    return acos(((c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y))/dist(a,b)/dist(b,c));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, r; cin >> n >> r;
    vector<Point> mines(n);
    for (auto &[x,y]:mines) cin >> x >> y;
    build(mines);
    n=mines.size();
    if (n==1) return cout << fixed << setprecision(4) << 2*PI*r << '\n', 0;
    mines.push_back(mines[0]);
    mines.push_back(mines[1]);
    double ans=0;
    for (int i=1;i<=n;++i){
        ans+=dist(mines[i],mines[i-1]);
        ans+=r*(PI-angle(mines[i-1],mines[i],mines[i+1]));
    }
    cout << fixed << setprecision(4) << ans << '\n';
}