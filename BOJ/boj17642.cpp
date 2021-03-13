#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int n, q; ll w;
struct Edge{ int n; ll w; int nxt; } adj[2*MAXN]; int head[MAXN], T;
int et[2*MAXN], dep[MAXN], in[MAXN], out[MAXN];
ll dist[MAXN];
struct Node{
    ll min, max, l, r, ans, lz; bool flag;
} st[4*MAXN];

void dfs(int v, int p){
    et[++T]=v; in[v]=T;
    for (int i=head[v];i!=0;i=adj[i].nxt){
        Edge x=adj[i];
        if (x.n==p) continue;
        dist[x.n]=dist[v]+x.w;
        dep[x.n]=dep[v]+1;
        dfs(x.n,v);
        et[++T]=v;
    }
    out[v]=T;
}

void push(int v, int l, int r){
    if (!st[v].flag) return;
    ll lz=st[v].lz; st[v].flag=0; st[v].lz=0;
    st[v].min+=lz; st[v].max+=lz;
    st[v].l-=lz; st[v].r-=lz;
    if (l==r) return;
    st[v+1].lz+=lz; st[v+1].flag=1;
    st[v+2*((l+r>>1)-l+1)].lz+=lz; st[v+2*((l+r>>1)-l+1)].flag=1;
    
}

Node pull(const Node &l, const Node &r){
    Node t; t.lz=t.flag=0;
    t.min=min(l.min,r.min);
    t.max=max(l.max,r.max);
    t.l=max({l.l,r.l,l.max-2*r.min});
    t.r=max({l.r,r.r,r.max-2*l.min});
    t.ans=max({l.ans,r.ans,l.l+r.max,l.max+r.r});
    return t;
}

void build(int v=1, int l=1, int r=2*n-1){
    if (l==r) return void(st[v]={dist[et[l]],dist[et[l]],-dist[et[l]],-dist[et[l]],0,0,0});
    int mid=l+r>>1;
    build(v+1,l,mid), build(v+2*(mid-l+1),mid+1,r);
    st[v]=pull(st[v+1],st[v+2*(mid-l+1)]);
}

void upd(int pl, int pr, ll val, int v=1, int l=1, int r=2*n-1){
    push(v,l,r);
    if (pl>r||pr<l) return;
    if (l>=pl&&r<=pr){
        st[v].lz+=val; st[v].flag=1;
        push(v,l,r);
        return;
    }
    int mid=l+r>>1;
    upd(pl,pr,val,v+1,l,mid); upd(pl,pr,val,v+2*(mid-l+1),mid+1,r);
    st[v]=pull(st[v+1],st[v+2*(mid-l+1)]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> w;
    for (int i=1;i<=n-1;++i){
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[++T]={b,c,head[a]}, head[a]=T;
        adj[++T]={a,c,head[b]}, head[b]=T;
    }
    T=0, dfs(1,1); build();
    ll last=0;
    while (q--){
        int v; ll val;
        cin >> v >> val;
        v=(v+last)%(n-1)+1;
        val=(val+last)%w;
        val-=adj[2*v].w;
        adj[2*v].w+=val; adj[2*v-1].w+=val;
        v=(dep[adj[2*v].n]>dep[adj[2*v-1].n]?adj[2*v].n:adj[2*v-1].n);
        upd(in[v],out[v],val);
        last=st[1].ans;
        cout << last << '\n';
    }
}