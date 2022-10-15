#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, q, dep[MAXN], in[MAXN], out[MAXN], T;
ll ans[MAXN];
vector<int> adj[MAXN];
struct Road{
    ll x, y, l, a;
    int node(){
        if (dep[x]>dep[y]) return x;
        else return y;
    }
    bool operator<(const Road &e) const{
        return l<e.l;
    }
} roads[MAXN];
struct Seg{
    ll a[2*MAXN], lz[2*MAXN];
    void push(int v, int l, int r){
        a[v]=gcd(a[v],lz[v]);
        if (l!=r){
            lz[lc]=gcd(lz[lc],lz[v]);
            lz[rc]=gcd(lz[rc],lz[v]);
        }
        lz[v]=0;
    }
    void upd(int ql, int qr, ll val, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ lz[v]=gcd(lz[v],val); push(v,l,r); return; }
        upd(ql,qr,val,lc,l,mid), upd(ql,qr,val,rc,mid+1,r);
        a[v]=gcd(a[lc],a[rc]);
    }
    ll qry(int ql, int qr, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l>qr||r<ql) return 0;
        if (l>=ql&&r<=qr) return a[v];
        return gcd(qry(ql,qr,lc,l,mid),qry(ql,qr,rc,mid+1,r));
    }
} st;
struct Query{
    ll src, w, id;
    bool operator<(const Query &e) const{
        return w<e.w;
    }
}; vector<Query> qs;

void dfs(int v, int p){
    in[v]=++T;
    for (int to:adj[v]){
        if (to==p) continue;
        dep[to]=dep[v]+1;
        dfs(to,v);
    }
    out[v]=T;
}

void solve(){
    cin >> n >> q;
    // reset
    T=0;
    qs.clear();
    for (int i=1;i<=n;++i){
        dep[i]=0;
        adj[i].clear();
        in[i]=out[i]=0;
    }
    ms(st.a,0), ms(st.lz,0);
    for (int i=1;i<n;++i){
        ll x, y, l, a; cin >> x >> y >> l >> a;
        adj[x].push_back(y);
        adj[y].push_back(x);
        roads[i]={x,y,l,a};
    }
    dfs(1,1);
    for (int i=1;i<=q;++i){
        ans[i]=0;
        ll src, w; cin >> src >> w;
        qs.push_back({src,w,i});
    }
    sort(qs.begin(),qs.end());
    sort(roads+1,roads+1+n-1);
    int poi=1;
    for (auto [src,w,id]:qs){
        while (poi<n&&roads[poi].l<=w){
            ll nd=roads[poi].node(), a=roads[poi].a; poi++;
            st.upd(in[nd],out[nd],a);
        }
        ans[id]=st.qry(in[src],in[src]);
    }
    for (int i=1;i<=q;++i) cout << ans[i] << " ";
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}