#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

int c[MAXN], h[MAXN];
ll ans, up[MAXN][2];
struct Edge{ int to, nxt; } adj[2*MAXN];

void dfs(int v, int p){
    up[v][0]=up[v][1]=1;
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].to;
        if (to==p) continue;
        dfs(to,v);
        ans=(ans-up[to][!c[v]]+mod)%mod;
        up[v][0]=up[v][0]*(1+up[to][0])%mod;
        up[v][1]=up[v][1]*(1+up[to][1])%mod;
    }
    up[v][0]=up[v][0]-1+(c[v]==0);
    up[v][1]=up[v][1]-1+(c[v]==1);
    ans=(ans+up[v][0]+up[v][1])%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        char a; cin >> a;
        c[i]=a=='B';
    }
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[2*i-1]={b,h[a]}, h[a]=2*i-1;
        adj[2*i-0]={a,h[b]}, h[b]=2*i-0;
    }
    dfs(1,1);
    cout << ans << '\n';
}