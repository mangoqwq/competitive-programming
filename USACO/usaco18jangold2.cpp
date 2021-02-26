#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, k, c[MAXN];
vector<int> adj[MAXN];

int dfs1(int v, int p){
    c[v]=inf;
    for (int to:adj[v]){
        if (to==p) continue;
        c[v]=min(c[v],dfs1(to,v)+1);
    }
    if (c[v]==inf) c[v]=0;
    return c[v];
}

int dfs2(int v, int p, int d){
    if (d>=c[v]) return 1;
    int tot=0;
    for (int to:adj[v]){
        if (to==p) continue;
        tot+=dfs2(to,v,d+1);
    }
    return tot;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(k,k);
    cout << dfs2(k,k,0) << '\n';
}