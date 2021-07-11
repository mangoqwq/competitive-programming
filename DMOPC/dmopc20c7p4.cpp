#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, q;
struct Seg{
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
} st1, st2;
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
int lca(int a, int b){
    for (;head[a]!=head[b];b=par[head[b]]){
        if (dep[head[a]]>dep[head[b]]) swap(a,b);
    }
    if (dep[a]>dep[b]) swap(a,b);
    return a;
}
int val[MAXN];
int qry(int a, int b){
    int ret=0;
    for (;head[a]!=head[b];b=par[head[b]]){
        if (dep[head[a]]>dep[head[b]]) swap(a,b);
        ret+=st1.qry(in[head[b]],in[b]);
        ret-=st2.qry(in[head[b]],in[b]);
    }
    if (dep[a]>dep[b]) swap(a,b);
    ret+=st1.qry(in[a],in[b]);
    ret-=st2.qry(in[a],in[b]);
    if (val[a]) ret++;
    if (val[par[a]]) ret++;
    return ret;
}
void upd(int v, int x){
    st1.upd(in[v],in[v],x);
    st1.upd(in[par[v]],in[par[v]],x);
    st2.upd(in[v],in[v],x);
}

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
        int op; cin >> op;
        if (op==1){
            int a; cin >> a;
            if (val[a]==1) upd(a,-1);
            if (val[a]==0) upd(a,1);
            val[a]^=1;
        }
        if (op==2){
            int a, b; cin >> a >> b;
            cout << qry(a,b) << '\n';
        }
    }
}