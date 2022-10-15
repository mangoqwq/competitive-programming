#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e3+1;

ll itgcd(ll a, ll b){
    while (b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

struct Point{
    ll x, y;
    bool operator<(const Point &a) const{
        return tie(x,y)<tie(a.x,a.y);
    }
    bool operator==(const Point &a) const{
        return x==a.x&&y==a.y;
    }
    void red(){
        ll g=itgcd(x,y);
        if (g==0) return;
        x=x/g, y=y/g;
    }
    Point op(){ return {-x,-y}; }
} a[MAXN];
map<Point,int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i].x >> a[i].y;
    ll ans=0;
    for (int i=1;i<=n;++i){
        ll curr=0;
        cnt.clear();
        for (int j=i+1;j<=n;++j){
            Point vec={a[i].x-a[j].x,a[i].y-a[j].y};
            vec.red();
            ans+=curr;
            if (cnt.count(vec)) ans-=cnt[vec];
            if (cnt.count({-vec.x,-vec.y})) ans-=cnt[{-vec.x,-vec.y}];
            curr++;
            cnt[vec]++;
        }
    }
    cout << ans << '\n';
}