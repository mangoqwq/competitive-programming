#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define rep() for (int i=-1;i<=1;++i) for (int j=-1;j<=1;++j)
#define f first
#define s second
typedef pair<int,int> pii;
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e3+1;

int cnt[MAXN][MAXN], tot;
bool vis[MAXN][MAXN];
queue<pii> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int cx, cy, x, y, nx, ny;
    for (int cows=1;cows<=n;++cows){
        int a, b; cin >> a >> b; a+=1000, b+=1000;
        if (vis[a][b]){ cout << tot-cows << '\n'; continue; }
        vis[a][b]=1; tot++;
        rep(){
            if (abs(i)+abs(j)!=1) continue;
            x=a+i, y=b+j;
            cnt[x][y]++;
            if (vis[x][y]&&cnt[x][y]==3) q.push({x,y});
        }
        if (cnt[a][b]==3) q.push({a,b});
        while (!q.empty()){
            auto[cx,cy]=q.front(); q.pop();
            if (cnt[cx][cy]!=3) continue;
            rep(){
                if (abs(i)+abs(j)!=1) continue;
                x=cx+i, y=cy+j;
                if (!vis[x][y]) nx=x, ny=y;     
            }
            cx=nx, cy=ny;
            vis[cx][cy]=1; tot++;
            if (cnt[cx][cy]==3) q.push({cx,cy});
            rep(){
                if (abs(i)+abs(j)!=1) continue;
                x=cx+i, y=cy+j;
                cnt[x][y]++;
                if (!vis[x][y]) continue;
                if (cnt[x][y]==3) q.push({x,y});
            }
        }
        cout << tot-cows << '\n';
    }
}