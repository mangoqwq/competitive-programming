#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5, L=18;

vector<int> adj[MAXN];
int arr[MAXN], diff[MAXN], d[MAXN];
int up[MAXN][L+1], in[MAXN], out[MAXN], T;

void dfs(int v, int p){
    in[v]=++T;
    d[v]=d[p]+1;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to!=p) dfs(to,v);
    }
    out[v]=T;
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i) if (!is(up[a][i],b)) a=up[a][i];
    return up[a][0];
}

int solve(int v, int p){
    int a=0;
    for (int to:adj[v]) if (to!=p) a^=solve(to,v), diff[v]^=diff[to];
    a^=diff[v];
    arr[v]^=a;
    return a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    for (int i=1,a,b,v;i<=q;++i){
        cin >> a >> b >> v;
        int anc=lca(a,b);
        if ((d[anc]-d[a])%2==0) arr[anc]^=v;
        if ((d[a]+d[b]-2*d[anc])%2==0) diff[b]^=v;
        else if (b!=1) diff[up[b][0]]^=v;
        diff[a]^=v;
    }
    solve(1,1);
    for (int i=1;i<=n;++i) cout << arr[i] << " ";
    cout << '\n';
}