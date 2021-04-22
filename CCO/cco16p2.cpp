#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4001;
const double eps=1e-9, pi=3.14159265358979323846;

struct Point{
    ll x, y, w;
    double angle;
    double ang(const Point &ori) const{
        return atan2(y-ori.y,x-ori.x);
    }
    bool operator==(const Point &a) const{
        return x==a.x&&y==a.y;
    }
    bool operator!=(const Point &a) const{
        return !(*this==a);
    }
} a[MAXN], b[MAXN];

ll cross(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans=0;
    for (int i=1;i<=n;++i) cin >> a[i].x >> a[i].y >> a[i].w;
    for (int i=1;i<=n;++i){
        int p=0, curr=0, on=0;
        for (int j=1;j<=n;++j){
            if (j==i) continue;
            b[++p]=a[j];
            b[p].angle=b[p].ang(a[i]);
        }
        sort(b+1,b+1+p,[](Point a, Point b){ return a.angle<b.angle; });
        int j=0; queue<Point> q;
        while (j<n-1){
            if (j==0){
                for (int k=1;k<=n-1;++k){
                    if (cross(a[i],b[1],b[k])<0){
                        on+=b[k].w;
                        q.push(b[k]);
                    }
                }
            }
            while (!q.empty()&&cross(a[i],b[j+1],q.front())>=0){
                on-=q.front().w, q.pop();
            }
            j++; on+=b[j].w; q.push(b[j]);
            while (j!=n-1&&abs(b[j].angle-b[j+1].angle)<=eps){
                j++;
                on+=b[j].w;
                q.push(b[j]);
            }
            ans=max({ans,on,(int)(on+a[i].w)});
        }
    }
    cout << ans << '\n';
}