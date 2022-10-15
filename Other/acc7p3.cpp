#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Item { int a, b, c; };
vector<Item> q;
int f[MAXN], vis[MAXN], p[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int id){
    vis[v]=id;
    for (int to:adj[v]){
        if (vis[to]) continue;
        dfs(to,id);
    }
}

int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]); }
bool Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a!=b) return p[b]=a, 1;
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> f[i];
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int T=0;
    for (int i=1;i<=n;++i) if (!vis[i]) dfs(i,++T);
    iota(p+1,p+1+T,1);
    for (int i=2;i<=n;++i){
        q.push_back({vis[i-1],vis[i],f[i]-f[i-1]});
    }
    sort(q.begin(),q.end(),[](Item a, Item b){ return a.c<b.c; });
    ll ans=0;
    for (auto [a,b,c]:q){
        if (Union(a,b)) ans+=c;
    }
    cout << ans << '\n';
}