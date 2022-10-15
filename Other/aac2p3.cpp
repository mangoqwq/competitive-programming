#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1002;

int n, m;
struct Data{
    char grid;
    int mxr, mxc, g, ans;
} a[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Point{ int x, y; } q[6*MAXN*MAXN];
const int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int T;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) cin >> a[i][j].grid;
    ms(vis,1);
    for (int i=n;i>=1;--i) for (int j=m;j>=1;--j){
        vis[i][j]=0;
        if (a[i][j].grid=='X') a[i][j].mxr=a[i][j].mxc=a[i][j].g=0;
        else{
            a[i][j].mxc=a[i+1][j].mxc+1;
            a[i][j].mxr=a[i][j+1].mxr+1;
            a[i][j].g=min({a[i+1][j].mxc,a[i][j+1].mxr,a[i+1][j+1].g})+1;
        }
    }
    q[++T]={1,1};
    a[1][1].ans=a[1][1].g;
    for (int i=1;i<=T;++i){
        auto [x,y]=q[i];
        for (int i=0;i<4;++i){
            int nx=x+dx[i], ny=y+dy[i];
            if (!vis[nx][ny]&&a[nx][ny].ans<min(a[x][y].ans,a[nx][ny].g)){
                a[nx][ny].ans=min(a[x][y].ans,a[nx][ny].g), q[++T]={nx,ny};
            }
        }
    }
    int res=0;
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        if (i+a[i][j].ans>n&&j+a[i][j].ans>m) res=max(res,a[i][j].ans);
    }
    cout << res << '\n';
}