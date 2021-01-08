#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

struct Edge{ int n, nxt; } adj[2*MAXN];
int h[MAXN], T, dep[MAXN];
ll val[MAXN], tot;

void dfs1(int v, int p){
    dep[v]=dep[p]+1;
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].n;
        if (to!=p) dfs1(to,v);
    }
}

void dfs2(int v, int p, ll add){
    add+=val[v];
    val[v]=add;
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].n;
        if (to!=p) dfs2(to,v,add);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[++T]={b,h[a]}, h[a]=T;
        adj[++T]={a,h[b]}, h[b]=T;
    }
    dfs1(1,1);
    int q; cin >> q;
    while (q--){
        int t, e, x; cin >> t >> e >> x;
        int a=adj[2*e].n, b=adj[2*e-1].n;
        if (t==2) swap(a,b);
        if (dep[a]<dep[b]){
            val[b]-=x, tot+=x;
        }
        else{
            val[a]+=x;
        }
    }
    dfs2(1,1,0);
    for (int i=1;i<=n;++i) cout << tot+val[i] << '\n';
}