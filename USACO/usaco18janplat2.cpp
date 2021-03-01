#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=7e4+1;

int n, c[MAXN], deg[MAXN], T, ans[MAXN];
int sz[MAXN], marked[MAXN];
vector<int> adj[MAXN];

void bfs(){
    ms(c,0x3f);
    queue<int> q;
    for (int i=1;i<=n;++i) if (adj[i].size()==1) c[i]=0, q.push(i), ans[i]--;
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (c[to]>c[v]+1){
                c[to]=c[v]+1;
                q.push(to);
            }
        }
    }
}

int getsz(int v, int p){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==p||marked[to]) continue;
        sz[v]+=getsz(to,v);
    }
    return sz[v];
}

int findcen(int v, int p, int src){
    for (int to:adj[v]){
        if (to==p||marked[to]) continue;
        if (sz[to]*2>=sz[src]) return findcen(to,v,src);
    }
    return v;
}

struct Fenwick{
    int a[MAXN+1];
    void ins(int i, int v){ i++; for (i=max(i,1);i<MAXN;i+=i&-i) a[i]+=v; }
    int qry(int i){
        i++;
        int ret=0;
        for (;i;i-=i&-i) ret+=a[i];
        return ret;
    }
} bit;

void upd(int v, int p, int d, int x){
    bit.ins(c[v]-d,x*(2-deg[v]));
    for (int to:adj[v]){
        if (to==p||marked[to]) continue;
        upd(to,v,d+1,x);
    }
}

void dfs(int v, int p, int d){
    ans[v]+=bit.qry(d);
    for (int to:adj[v]){
        if (to==p||marked[to]) continue;
        dfs(to,v,d+1);
    }
}

void solve(int v){
    marked[v]=1;
    upd(v,v,0,1);
    ans[v]+=bit.qry(0);
    for (int to:adj[v]){
        if (marked[to]) continue;
        upd(to,v,1,-1);
        dfs(to,v,1);
        upd(to,v,1,1);
    }
    upd(v,v,0,-1);
    for (int u:adj[v]){
        if (marked[u]) continue;
        getsz(u,v);
        solve(findcen(u,v,u));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    bfs();
    getsz(1,1); solve(findcen(1,1,1));
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
}