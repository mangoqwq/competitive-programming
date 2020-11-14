#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, L=17;
const ll inf=0x3f3f3f3f3f3f3f3f;

int n, s, q, rt;
struct Edge{ int n; ll w; int nxt; } adj[2*MAXN], up[MAXN][L+1];
bool shop[MAXN];
int head[MAXN], t1, in[MAXN], out[MAXN], t2;
ll dist[MAXN], dep[MAXN];

ll dfs1(int v, int p){
    if (shop[v]) dist[v]=0;
    for (int i=head[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (to==p) continue;
        dep[to]=dep[v]+adj[i].w;
        dist[v]=min(dist[v],dfs1(to,v)+adj[i].w);
    }
    return dist[v];
}

void dfs2(int v, int p){
    in[v]=++t2;
    up[v][0]={p,min(dist[v],dist[p]+(dep[v]-dep[p]))};
    for (int i=1;i<=L;++i){
        int to=up[v][i-1].n; 
        up[v][i]={up[to][i-1].n,min(up[v][i-1].w,up[to][i-1].w+(dep[v]-dep[to]))};
    }
    for (int i=head[v];i!=0;i=adj[i].nxt){
        int to=adj[i].n;
        if (to==p) continue;
        dfs2(to,v);
    }
    out[v]=t2;
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int main(){
    ms(dist,0x3f);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> q >> rt;
    for (int i=1,a,b,c;i<n;++i){
        cin >> a >> b >> c;
        adj[++t1]={b,c,head[a]}, head[a]=t1;
        adj[++t1]={a,c,head[b]}, head[b]=t1;
    }
    for (int i=1,a;i<=s;++i) cin >> a, shop[a]=1;
    dfs1(rt,rt); dfs2(rt,rt);
    while (q--){
        int idx, src; cin >> idx >> src;
        int a=adj[2*idx].n, b=adj[2*idx-1].n;
        if (is(a,b)) swap(a,b);
        ll ans=dist[src], temp=0;
        if (is(a,src)){
            for (int i=L;i>=0;--i){
                if (!is(up[src][i].n,b)){
                    ans=min(ans,up[src][i].w+temp);
                    temp+=dep[src]-dep[up[src][i].n];
                    src=up[src][i].n;
                }
            }
            if (ans==inf) cout << "oo" << '\n';
            else cout << ans << '\n';
        } 
        else cout << "escaped" << '\n';
    }
}