#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

vector<int> adj[MAXN];
int sz[MAXN], reach[MAXN], par[MAXN], in[MAXN], low[MAXN], dep[MAXN], rt[MAXN], ord[MAXN], T;
stack<int> s;

void tarjan(int v){
    in[v]=low[v]=++T;
    sz[v]=1;
    s.push(v);
    for (int to:adj[v]){
        if (dep[to]){
            low[v]=min(low[v],in[to]);
        }
        else{
            dep[to]=dep[v]+1;
            par[to]=v;
            tarjan(to);
            sz[v]+=sz[to];
            low[v]=min(low[v],low[to]);
        }
    }
    if (in[v]==low[v]){
        rt[v]=1;
        while (int u=s.top()){
            s.pop(); reach[u]=sz[v];
            if (u==v) break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    dep[r]=1;
    tarjan(r);
    for (int i=1;i<=n;++i) cout << reach[i] << (i==n?'\n':' ');
    iota(ord+1,ord+1+n,1);
    sort(ord+1,ord+1+n,[](int a, int b){ return dep[a]>dep[b]; });
    int ans=0;
    for (int i=1;i<=n;++i){
        int v=ord[i];
        if (rt[v]){
            ans++;
            while (rt[v]) rt[v]=0, v=par[v];
        }
    }
    cout << ans << '\n';
}