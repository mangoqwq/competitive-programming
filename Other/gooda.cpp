#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int fun[MAXN], deg[MAXN], h1[MAXN], h2[MAXN], p;
int in[MAXN], low[MAXN], scc[MAXN], cnt=0, T;
stack<int> s;
ll dp[MAXN], val[MAXN];
struct Edge{ int n, nxt; } adj[MAXN], dag[MAXN];

void dfs(int v){
    in[v]=low[v]=++T; s.push(v);
    for (int i=h1[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (!in[to]) dfs(to), low[v]=min(low[v],low[to]);
        else if (!scc[to]) low[v]=min(low[v],in[to]);
    }
    if (in[v]==low[v]){
        cnt++;
        while (1){
            int u=s.top(); s.pop();
            scc[u]=cnt; val[cnt]+=fun[u];
            for (int i=h1[u];i!=0;i=adj[i].nxt){
                int to=adj[i].n;
                if (cnt!=scc[to]) dag[++p]={scc[to],h2[cnt]}, h2[cnt]=p, deg[scc[to]]++;
            }
            if (u==v) break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i=1;i<=n;++i) cin >> fun[i];
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        adj[++p]={b,h1[a]}, h1[a]=p;
    }
    p=0, dfs(s);
    queue<int> q;
    ms(dp,-0x3f); dp[cnt]=val[cnt];
    for (int i=1;i<=cnt;++i){
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int i=h2[v];i!=0;i=dag[i].nxt){
            int to=dag[i].n;
            deg[to]--;
            if (deg[to]==0) q.push(to);
            dp[to]=max(dp[to],dp[v]+val[to]);
        }
    }
    cout << dp[scc[e]] << '\n';

}