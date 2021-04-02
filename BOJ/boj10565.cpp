#include <bits/stdc++.h>

using namespace std;
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
const int MAXN=1e6+1, inf=0x3f3f3f3f;

vector<int> c[MAXN];
int n, in[MAXN], out[MAXN], T;
int mn[2*MAXN], mx[2*MAXN], lz[2*MAXN];

void push(int v, int l, int r){
    mn[v]+=lz[v]; mx[v]+=lz[v];
    if (l!=r){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}

void upd(int ql, int qr, int val, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (l>qr||r<ql) return;
    if (l>=ql&&r<=qr){
        lz[v]+=val; push(v,l,r);
        return;
    }
    upd(ql,qr,val,lc,l,mid), upd(ql,qr,val,rc,mid+1,r);
    mn[v]=min(mn[lc],mn[rc]);
    mx[v]=max(mx[lc],mx[rc]);
}

int qrymx(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (l>qr||r<ql) return 0;
    if (l>=ql&&r<=qr) return mx[v];
    return max(qrymx(ql,qr,lc,l,mid),qrymx(ql,qr,rc,mid+1,r));
}

int qrymn(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (l>qr||r<ql) return inf;
    if (l>=ql&&r<=qr) return mn[v];
    return min(qrymn(ql,qr,lc,l,mid),qrymn(ql,qr,rc,mid+1,r));
}

void dfs(int v){
    in[v]=++T;
    for (int to:c[v]) dfs(to);
    out[v]=T;
}

void solve(){
    T=0;
    cin >> n;
    for (int i=1;i<=n;++i) c[i].clear();
    for (int i=1;i<=2*n;++i) mn[i]=mx[i]=lz[i]=0;
    for (int i=2;i<=n;++i){
        int par; cin >> par;
        c[par].push_back(i);
    }
    dfs(1);
    for (int i=1;i<=n;++i){
        int val; cin >> val;
        upd(in[i],in[i],val);
    }
    int q; cin >> q;
    while (q--){
        char op; cin >> op;
        if (op=='Q'){
            int v; cin >> v;
            cout << qrymx(in[v],out[v])-qrymn(in[v],out[v]) << '\n';
        }
        if (op=='R'){
            int i, v; cin >> i >> v;
            upd(in[i],out[i],v);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}