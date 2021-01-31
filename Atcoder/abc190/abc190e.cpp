#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, inf=0x3f3f3f3f;

int n, m, k;
vector<int> adj[MAXN];
int c[17], d[17][17], dist[MAXN];
int dp[(1<<17)][17];
queue<int> q;

void bfs(int src){
    q.push(c[src]);
    ms(dist,0x3f);
    dist[c[src]]=0;
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int x:adj[v]){
            if (dist[x]==inf){
                dist[x]=dist[v]+1;
                q.push(x);
            }
        }
    }
    for (int i=0;i<k;++i) d[src][i]=dist[c[i]];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> k;
    for (int i=0;i<k;++i) cin >> c[i];
    ms(dp,0x3f);
    for (int i=0;i<k;++i) bfs(i), dp[(1<<i)][i]=1;
    int lim=(1<<k)-1;
    for (int i=1;i<lim;++i){
        for (int j=0;j<k;++j){
            if (1&(i>>j)) continue;
            for (int x=0;x<k;++x){
                if (!(1&(i>>x))) continue;
                dp[i+(1<<j)][j]=min(dp[i+(1<<j)][j],dp[i][x]+d[x][j]);
            }
        }
    }
    int ans=inf;
    for (int i=0;i<k;++i) ans=min(ans,dp[lim][i]);
    if (ans==inf) cout << -1 << '\n';
    else cout << ans << '\n';
}