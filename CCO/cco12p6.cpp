#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

struct Point{
    ll x, y;
    double ang() const{
        return atan2(x,y);
    }
    bool operator<(const Point &a) const{
        return ang()<a.ang();
    }
} e[MAXN], f[MAXN];
int dp[MAXN][MAXN];
double cross(Point a, Point b, Point c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
bool in_triangle(int i, int j, Point p){
    if (i>j) swap(i,j);
    return  (cross(e[i],e[j],p)<=0) &&
            (cross(e[j],{0,0},p)<=0) &&
            (cross({0,0},e[i],p)<=0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> e[i].x >> e[i].y;
    for (int i=1;i<=m;++i) cin >> f[i].x >> f[i].y;
    sort(e+1,e+1+n); ms(dp,-0x3f);
    int ans=0;
    for (int i=1;i<=n;++i){
        dp[i][0]=1;
        for (int j=1;j<i;++j){
            int add=0;
            for (int x=j+1;x<i;++x) add+=in_triangle(j,i,e[x]);
            for (int x=1;x<=m;++x) add-=in_triangle(j,i,f[x]);
            for (int k=0;k<j;++k){
                if (cross(e[k],e[j],e[i])>=0) continue;
                dp[i][j]=max(dp[i][j],dp[j][k]+1+add);
            }
        }
    }
    for (int i=0;i<=n;++i) for (int j=0;j<=n;++j) ans=max(ans,dp[i][j]);
    cout << ans << '\n';
}