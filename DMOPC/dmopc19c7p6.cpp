#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1, L=19;

int n, k; 
vector<int> adj[MAXN];
int dist[MAXN], up[MAXN][L+1], in[MAXN], out[MAXN], T;
int mind[MAXN], rad[MAXN];
bool vis[MAXN];
int bit[MAXN], sz[MAXN], ans[MAXN];

void dfs0(int v, int p){
    in[v]=++T;
    dist[v]=dist[p]+1;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to==p) continue;
        dfs0(to,v);
    }
    out[v]=T;
}

bool is_anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

void upd(int i, int val=1){
    if (i<=0) return;
    for (;i<MAXN;i+=i&-i) bit[i]+=val;
}

int get(int i){
    int ret=0;
    for (;i>=1;i-=i&-i) ret+=bit[i];
    return ret;
}

int get_dist(int a, int b){ return dist[a]+dist[b]-2*dist[lca(a,b)]; }

int getsz(int v, int p){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==p||vis[to]) continue;
        sz[v]+=getsz(to,v);
    }
    return sz[v];
}

int getcen(int v, int p, int rt){
    for (int to:adj[v]){
        if (to==p||vis[to]) continue;
        if (sz[to]*2>sz[rt]) return getcen(to,v,rt);
    }
    return v;
}

int tot, add;
int op[MAXN], top;
int stk[MAXN], top2;

void dfs(int v, int p, int d){
    if (rad[v]>=d) add++;
    if (rad[v]>d) op[++top]=rad[v]-d;
    ans[v]+=tot-get(d-1);
    for (int to:adj[v]){
        if (to==p||vis[to]) continue;
        dfs(to,v,d+1);
    }
}

void solve(int v, int dep){
    tot=0; add=0;
    if (rad[v]>=0) add++;
    if (rad[v]>=1) upd(rad[v]), stk[++top2]=rad[v], tot+=1;
    for (int i=0;i<adj[v].size();++i){
        int to=adj[v][i];
        if (vis[to]) continue;
        dfs(to,v,1);
        while (top!=0) stk[++top2]=op[top], upd(op[top--]), tot++;
    }
    ans[v]+=add;
    while (top2!=0) upd(stk[top2--],-1), tot--;
    for (int i=adj[v].size()-1;i>=0;--i){
        int to=adj[v][i];
        if (vis[to]) continue;
        dfs(to,v,1);
        while (top!=0) stk[++top2]=op[top], upd(op[top--]), tot++;
    }
    while (top2!=0) upd(stk[top2--],-1), tot--;

    for (int to:adj[v]){
        if (vis[to]) continue;
        getsz(to,v);
        int cen=getcen(to,v,to);
        vis[cen]=1;
        solve(cen,dep+1);
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ms(mind,0x3f);
    queue<int> q;
    for (int i=1,a;i<=k;++i) cin >> a, mind[a]=0, q.push(a);
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (mind[v]+1<mind[to]) q.push(to), mind[to]=mind[v]+1;
        }
    }
    dfs0(1,1);
    for (int i=1;i<=n;++i){
        int f,p; cin >> f >> p;
        rad[i]=min(mind[i],get_dist(i,f)-p-1);
    }
    getsz(1,1);
    int cen=getcen(1,1,1);
    vis[cen]=1;
    solve(cen,0);
    for (int i=1;i<=n;++i) cout << ans[i] << " ";
    cout << '\n';
}