#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5;

int n, a, b;
int mapping[3], sz[MAXN], rt[MAXN], T;
bool vis[MAXN];
vector<int> graph[MAXN], adj[MAXN], ans;
set<int> seen, cadj[MAXN];
int tot=0;

void build(int v){
    vis[v]=1;
    for (int to:graph[v]){
        if (vis[to]) continue;
        adj[to].push_back(v);
        adj[v].push_back(to);
        build(to);
    }
}

int dfs(int v, int p, int col){
    sz[v]=1; rt[v]=col;
    for (int to:adj[v]){
        if (to==p) continue;
        sz[v]+=dfs(to,v,col);
    }
    return sz[v];
}

void flood(int v){
    vis[v]=1;
    seen.insert(v);
    tot+=sz[v];
    if (tot>=a) return;
    for (int to:cadj[v]){
        if (seen.count(to)) continue;
        flood(to);
        if (tot>=a) return;
    }
}

int centroid(int v, int p){
    for (int to:adj[v]){
        if (to==p) continue;
        if (sz[to]*2>n) return centroid(to,v);
    }
    return v;
}

void paint(int v, int p, int &cnt, int col, bool block=0){
    vis[v]=1;
    if (cnt) cnt--, ans[v]=col;
    for (int to:graph[v]){
        if (ans[to]||to==p||vis[to]) continue;
        if (block&&!seen.count(rt[to])) continue;
        paint(to,v,cnt,col,block);
    }
}

vector<int> construct(int cen){
    ms(vis,0);
    paint(*seen.begin(),-1,a,mapping[0],1);
    ms(vis,0);
    paint(cen,cen,b,mapping[1]);
    for (int i=0;i<n;++i) if (!ans[i]) ans[i]=mapping[2];
    return ans;
}

vector<int> find_split(int N, int A, int B, int C, vector<int> p, vector<int> q){
    n=N;
    vector<pair<int,int>> m={{A,1},{B,2},{C,3}};
    sort(m.begin(),m.end());
    for (int i=0;i<=2;++i) mapping[i]=m[i].second;
    a=m[0].first, b=m[1].first;
    ans.resize(n);
    for (int i=0;i<p.size();++i){
        int u=p[i], v=q[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    build(0);
    dfs(0,0,-1);
    int cen=centroid(0,0);
    rt[cen]=-1;
    for (int to:adj[cen]) dfs(to,cen,to);
    for (int i=0;i<p.size();++i){
        int u=p[i], v=q[i];
        u=rt[u], v=rt[v];
        if (u!=v&&u!=-1&&v!=-1){
            cadj[u].insert(v);
            cadj[v].insert(u);
        }
    }
    for (int to:adj[cen]){
        if (sz[to]>=a){
            seen.insert(to);
            return construct(cen);
        }
    }
    ms(vis,0);
    for (int to:adj[cen]){
        if (vis[to]) continue;
        tot=0; seen.clear();
        flood(to);
        if (tot>=a) return construct(cen);
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
    vector<int> p(m), q(m);
    for (int i=0;i<m;++i) cin >> p[i] >> q[i];
    vector<int> ret=find_split(n,a,b,c,p,q);
    for (int x:ret) cout << x << " ";
    cout << '\n';
}