#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=20;

int vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int c, bool &ans){
    vis[v]=c;
    for (int to:adj[v]){
        if (vis[to]==-1) dfs(to,c^1,ans);
        else if (vis[to]==vis[v]) ans=0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int all=(1<<n)-1;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans=0;
    for (int i=0;i<(1<<n);++i){
        bool can=1;
        for (int v=0;v<n;++v){
            if (!(1&(i>>v))) continue;
            for (int to:adj[v]){
                if (1&(i>>to)) can=0;
            }
        }
        if (!can) continue;
        ms(vis,-1);
        for (int v=0;v<n;++v) if (1&(i>>v)) vis[v]=2;
        ll curr=1;
        for (int v=0;v<n;++v){
            if (vis[v]==-1) dfs(v,0,can), curr*=2;
        }
        if (can) ans+=curr;
    }
    cout << ans << '\n';
}