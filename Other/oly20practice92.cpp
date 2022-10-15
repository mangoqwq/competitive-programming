#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+1;

int n, q;
struct Query{ int x, n, idx, c; }; vector<Query> qs;
int par[MAXN], hvy[MAXN], head[MAXN], sz[MAXN], in[MAXN], out[MAXN], T;
ll ans[MAXN], st[2*MAXN], lz[2*MAXN];
vector<int> adj[MAXN];

void push(int v, int l, int r){
    if (!lz[v]) return;
    st[v]+=(r-l+1)*lz[v];
    if (l!=r){
        lz[v+1]+=lz[v];
        lz[v+2*((l+r>>1)-l+1)]+=lz[v];
    }
    lz[v]=0;
}

int get(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (ql>r||qr<l) return 0;
    if (l>=ql&&r<=qr) return st[v];
    int mid=l+r>>1;
    return get(ql,qr,v+1,l,mid)+get(ql,qr,v+2*(mid-l+1),mid+1,r);
}

void upd(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (ql>r||qr<l) return;
    if (l>=ql&&r<=qr){ lz[v]++, push(v,l,r); return; }
    int mid=l+r>>1;
    upd(ql,qr,v+1,l,mid); upd(ql,qr,v+2*(mid-l+1),mid+1,r);
    st[v]=st[v+1]+st[v+2*(mid-l+1)];
}

bool cmp(Query a, Query b){ return a.x < b.x; }

void dfs1(int v){
    
    sz[v]=1;
    for (int to:adj[v]){
        par[to]=v;
        dfs1(to);
        sz[v]+=sz[to];
        if (sz[to]>sz[hvy[v]]) hvy[v]=to;
    }
}
void dfs2(int v){
    in[v]=++T;
    if (hvy[v]) head[hvy[v]]=head[v], dfs2(hvy[v]);
    for (int to:adj[v]){
        if (to==hvy[v]) continue;
        head[to]=to, dfs2(to);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=2;i<=n;++i){
        int a; cin >> a; a++;
        adj[a].push_back(i);
    }
    for (int i=1,l,r,x;i<=q;++i){
        cin >> l >> r >> x; l++, r++, x++;
        qs.push_back({l-1,x,i,-1});
        qs.push_back({r,x,i,1});
    }
    sort(qs.begin(),qs.end(),cmp);
    dfs1(1), head[1]=1, dfs2(1);
    int p=0;
    for (Query x:qs){
        while (x.x>p){
            p++;
            for (int i=p;i;i=par[head[i]]) upd(in[head[i]],in[i]);
        }
        for (int i=x.n;i;i=par[head[i]]) ans[x.idx]+=get(in[head[i]],in[i])*x.c;
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}