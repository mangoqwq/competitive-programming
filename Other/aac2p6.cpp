#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, q;
namespace Seg{
    ll a[2*MAXN], lz[2*MAXN];
    void push(int v, int l, int r){
        a[v]+=lz[v]*(r-l+1);
        if (l!=r) lz[lc]+=lz[v], lz[rc]+=lz[v];
        lz[v]=0;
    }
    void upd(int ql, int qr, ll x, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ lz[v]+=x, push(v,l,r); return; }
        upd(ql,qr,x,lc,l,mid), upd(ql,qr,x,rc,mid+1,r);
        a[v]=a[lc]+a[rc];
    }
    ll qry(int ql, int qr, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l>qr||r<ql) return 0;
        if (l>=ql&&r<=qr) return a[v];
        return qry(ql,qr,lc,l,mid)+qry(ql,qr,rc,mid+1,r);
    }
}
vector<int> adj[MAXN];
int par[MAXN], son[MAXN], sz[MAXN], head[MAXN], dep[MAXN], in[MAXN], out[MAXN], T;
void dfs(int v){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==par[v]) continue;
        par[to]=v; dep[to]=dep[v]+1;
        dfs(to); sz[v]+=sz[to];
        if (sz[to]>sz[son[v]]) son[v]=to;
    }
}

void dfs1(int v, int h){
    in[v]=++T;
    head[v]=h;
    if (son[v]) dfs1(son[v],h);
    for (int to:adj[v]){
        if (to==par[v]||to==son[v]) continue;
        dfs1(to,to);
    }
    out[v]=T;
}
bool isanc(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }
void upd(int v, int x){
    while (v) Seg::upd(in[head[v]],in[v],x), v=par[head[v]];
}
ll qry(int v){
    ll ret=0;
    while (v) ret+=Seg::qry(in[head[v]],in[v],1), v=par[head[v]];
    return ret;
}
int qs[MAXN];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dep[1]=1, dfs(1), dfs1(1,1);
    while (q--){
        int m; cin >> m;
        for (int i=1;i<=m;++i) cin >> qs[i];
        ll ans=0, best=0;
        for (int i=1;i<=m;++i){
            ans+=dep[qs[i]];
            upd(qs[i],1);
        }
        for (int i=1;i<=m;++i) best=max(best,(ll)qry(qs[i]));
        cout << ans-best << '\n';
        for (int i=1;i<=m;++i) upd(qs[i],-1);
    }
}