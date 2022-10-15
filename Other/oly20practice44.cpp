#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1, L=31-__builtin_clz(MAXN);

struct Edge{ int to, w, nxt; };
int n; vector<int> tree[MAXN];
int in[MAXN], out[MAXN], up[MAXN][L+1], dist[MAXN], T;
Edge adj[2*MAXN];
int k; int head[MAXN];
vector<int> vec;
int on[MAXN];

void dfs0(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:tree[v]){
        if (to==p) continue;
        dist[to]=dist[v]+1;
        dfs0(to,v);
    }
    out[v]=T;
}
bool is_anc(int a, int b){ return (in[a]<=in[b])&&(out[a]>=out[b]); }
int lca(int a, int b){ 
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
bool cmp(int a, int b){ return in[a]<in[b]; }
void join(int a, int b){
    int d=dist[b]-dist[a];
    adj[++T]={b,d,head[a]}, head[a]=T;
    adj[++T]={a,d,head[b]}, head[b]=T;
}
void build(){
    T=0;
    sort(vec.begin(),vec.end(),cmp);
    for (int i=1;i<k;++i) vec.push_back(lca(vec[i],vec[i-1]));
    sort(vec.begin(),vec.end(),cmp);
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    for (int v:vec){ head[v]=0; }
    stack<int> s;
    for (int v:vec){
        while (!s.empty()&&!is_anc(s.top(),v)){
            int u=s.top(); s.pop();
            join(s.top(),u);
        }
        s.push(v);
    }
    while (s.size()>1){
        int u=s.top(); s.pop();
        join(s.top(),u);
    }
}

namespace Solve{
    int mn, mx; ll tot;
    int mn1[MAXN], mn2[MAXN], mx1[MAXN], mx2[MAXN]; ll sz[MAXN];
    void dfs(int v, int p, ll last){
        sz[v]=0; mn1[v]=mn2[v]=inf; mx1[v]=mx2[v]=-inf;
        if (on[v]){
            sz[v]=1;
            mn1[v]=mx1[v]=0;
        }
        for (int i=head[v];i;i=adj[i].nxt){
            auto [to,w,nxt]=adj[i];
            if (to==p) continue;

            dfs(to,v,w);
            int d;

            d=mn1[to]+w;
            if (d<=mn1[v]) mn2[v]=mn1[v], mn1[v]=d;
            else if (d<mn2[v]) mn2[v]=d;
            mn=min(mn,mn1[v]+mn2[v]);

            d=mx1[to]+w;
            if (d>=mx1[v]) mx2[v]=mx1[v], mx1[v]=d;
            else if (d>mx2[v]) mx2[v]=d;
            mx=max(mx,mx1[v]+mx2[v]);

            sz[v]+=sz[to];
        }
        tot+=(sz[v]*(k-sz[v]))*last;
    } 
    void go(){
        tot=0; mn=inf, mx=0;
        dfs(vec[0],vec[0],0);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    scan(n);
    for (int i=1;i<=n-1;++i){
        int a, b; scan(a); scan(b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs0(1,1);
    int q; scan(q);
    while (q--){
        scan(k);
        vec.resize(k);
        for (int &x:vec) scan(x);
        for (int x:vec) on[x]=1;
        build();
        Solve::go();
        cout << Solve::tot << " ";
        cout << Solve::mn << " ";
        cout << Solve::mx << '\n';
        for (int x:vec) on[x]=0;
    }
}