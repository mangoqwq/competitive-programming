#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1, L=20;

int n, q, r;
int in[MAXN], out[MAXN], ett[2*MAXN], up[MAXN][L+1], T, head[MAXN];
struct Edge{ int n, nxt;} adj[2*MAXN];
ll val[MAXN];
struct Node{
    ll pos, neg, val, lz;
    Node merge(Node a){
        Node x;
        x.pos=a.pos+pos;
        x.neg=a.neg+neg;
        x.val=a.val+val;
        x.lz=0;
        return x;
    }
} t[8*MAXN];

void dfs(int v, int p){
    in[v]=++T, ett[T]=v;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int i=head[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (to==p) continue;
        dfs(to,v);
    }
    out[v]=++T, ett[T]=v;
}

bool is_anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int Lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

void build(int v, int l, int r){
    if (l==r){
        if (in[ett[l]]==l) t[v].pos++, t[v].val=val[ett[l]];
        if (out[ett[l]]==l) t[v].neg++, t[v].val=-val[ett[l]];
        // cout << l << " " << v << " " << t[v].val << '\n';
        return;
    }
    int mid=l+r>>1;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    t[v]=t[v*2].merge(t[v*2+1]);
}

void push(int v, int l, int r){
    if (t[v].lz==0) return;
    t[v].val+=(t[v].pos-t[v].neg)*t[v].lz;
    if (l!=r){
        t[2*v].lz+=t[v].lz;
        t[2*v+1].lz+=t[v].lz;
    }
    t[v].lz=0;
}

ll get(int v, int l, int r, int ql, int qr){
    // cout << v << " " << l << " " << r << " " << ql << " " << qr << " " << t[v].val << '\n';
    push(v,l,r);
    if (ql>r||qr<l) return 0;
    if (l>=ql&&r<=qr) return t[v].val;
    int mid=l+r>>1;
    return get(v*2,l,mid,ql,qr)+get(v*2+1,mid+1,r,ql,qr);
}

void upd(int v, int l, int r, int ql, int qr, ll x){
    // cout << v << " " << l << " " << r << " " << ql << " " << qr << " " << x << '\n';
    push(v,l,r);
    if (ql>r||qr<l) return;
    if (l>=ql&&r<=qr){ t[v].lz+=x; push(v,l,r); return; }
    int mid=l+r>>1;
    upd(2*v,l,mid,ql,qr,x);
    upd(2*v+1,mid+1,r,ql,qr,x);
    t[v]=t[v*2].merge(t[v*2+1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> r;
    for (int i=1;i<=n;++i) cin >> val[i];
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        adj[++T]={b,head[a]}, head[a]=T;
        adj[++T]={a,head[b]}, head[b]=T;
    }
    T=0; dfs(r,r);
    build(1,1,2*n);
    for (int i=1,op,a,b;i<=q;++i){
        cin >> op >> a >> b;
        if (op==1){
            upd(1,1,2*n,in[a],in[a],b);
            upd(1,1,2*n,out[a],out[a],b);
        }
        if (op==2){
            upd(1,1,2*n,in[a],out[a],b);
        }
        if (op==3){
            int lca=Lca(a,b);
            cout << get(1,1,2*n,in[lca],in[a])+get(1,1,2*n,in[lca],in[b])-get(1,1,2*n,in[lca],in[lca]) << '\n';
        }
    }
}