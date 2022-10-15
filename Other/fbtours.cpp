#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5;

int n, m, q;
struct Edge{ int n, nxt; } graph[MAXN*10], adj[MAXN*10];
int p1, p2, h1[MAXN], h2[MAXN];
int dfn[MAXN], low[MAXN], bcc[MAXN], rt[MAXN], stk[MAXN], baka, T, top;
int in[MAXN], out[MAXN], hvy[MAXN], par[MAXN], head[MAXN], sz[MAXN]; bool vis[MAXN];
int bit[MAXN], val[MAXN];

void tarjan(int v, int p){
    low[v]=dfn[v]=++T, stk[++top]=v;
    rt[v]=rt[p];
    for (int i=h1[v];i!=0;i=graph[i].nxt){
        int to=graph[i].n;
        if (to==p) continue;
        if (dfn[to]) low[v]=min(low[v],dfn[to]);
        else tarjan(to,v), low[v]=min(low[v],low[to]);
    }
    if (low[v]==dfn[v]){
        baka++;
        while (top!=0){
            int a=stk[top]; top--;
            bcc[a]=baka;
            if (a==v) break;
        }
    }
}

void dfs0(int v){
    vis[v]=1;
    for (int i=h1[v];i!=0;i=graph[i].nxt){
        int to=graph[i].n;
        if (vis[to]) continue;
        if (bcc[v]!=bcc[to]){
            adj[++p2]={bcc[v],h2[bcc[to]]}, h2[bcc[to]]=p2;
            adj[++p2]={bcc[to],h2[bcc[v]]}, h2[bcc[v]]=p2;
        }
        dfs0(to);
    }
}

int dfs1(int v){
    sz[v]=1;
    for (int i=h2[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (to==par[v]) continue;
        par[to]=v;
        sz[v]+=dfs1(to);
        if (sz[to]>sz[hvy[v]]) hvy[v]=to;
    }
    return sz[v];
}

void dfs2(int v){
    in[v]=++T;
    if (hvy[v]) head[hvy[v]]=head[v], dfs2(hvy[v]);
    for (int i=h2[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (to==par[v]||to==hvy[v]) continue;
        head[to]=to, dfs2(to);
    }
    out[v]=T;
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; };

void upd(int l, int r, int val){
    for (;l<MAXN;l+=l&-l) bit[l]+=val;
    for (++r;r<MAXN;r+=r&-r) bit[r]-=val;
}

int query(int i){
    int ret=0;
    for (;i>0;i-=i&-i) ret+=bit[i];
    return ret;
}

void paint(int a, int b, int val){
    if (rt[a]!=rt[b]) return;
    a=bcc[a], b=bcc[b];
    while (head[a]!=head[b]){
        if (is(head[b],head[a])) swap(a,b);
        upd(in[head[b]],in[b],val);
        b=par[head[b]];
    }
    if (is(b,a)) swap(a,b);
    upd(in[a],in[b],val);
}

void reset(){
    p1=p2=0;
    T=baka=top=0;
    for (int i=1;i<=n;++i){
        h1[i]=h2[i]=0;
        dfn[i]=low[i]=bcc[i]=rt[i]=stk[i]=0;
        in[i]=out[i]=hvy[i]=par[i]=head[i]=sz[i]=vis[i]=0;
        val[i]=0;
    }
    ms(bit,0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("txt.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--){
        cin >> n >> m >> q;
        reset();
        for (int i=1,a,b;i<=m;++i){
            cin >> a >> b;
            graph[++p1]={b,h1[a]}, h1[a]=p1;
            graph[++p1]={a,h1[b]}, h1[b]=p1;
        }
        for (int i=1;i<=n;++i)
            if (!dfn[i]) rt[i]=i, tarjan(i,i);
        T=0;
        for (int i=1;i<=n;++i){
            if (rt[i]!=i) continue;
            dfs0(i), dfs1(bcc[i]);
            head[bcc[i]]=bcc[i], dfs2(bcc[i]);
        }
        char op; int a, b, x;
        ll ans=0;
        for (int i=1;i<=q;++i){
            cin >> op;
            if (op=='T'){
                cin >> a >> b >> x;
                paint(a,b,x);
            }
            if (op=='S'){
                cin >> x;
                int curr=query(in[bcc[x]])-val[x];
                ans+=curr; ans%=mod;
                val[x]+=curr;
            }
        }
        // for (int i=1;i<=n;++i) cout << dfn[i] << " ";
        cout << ans << '\n';
    }
}