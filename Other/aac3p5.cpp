#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

struct Item{
    int sz, id;
    bool operator<(const Item &x) const{
        return tie(sz,id)<tie(x.sz,x.id);
    }
} psa[MAXN+2];
int a[MAXN], sz[MAXN];
vector<int> adj[MAXN];
set<int> s[MAXN];

int dfs(int v, int p){
    s[v].insert(a[v]);
    sz[v]=1;
    int mex=1;
    if (a[v]==1) mex=2;
    for (int to:adj[v]){
        if (to==p) continue;
        int ret=dfs(to,v);
        sz[v]+=sz[to];
        if (s[to].size()>s[v].size()) swap(s[to],s[v]);
        for (int x:s[to]) s[v].insert(x);
        mex=max(mex,ret);
    }
    while (s[v].count(mex)) mex++;
    psa[mex]=min(psa[mex],{sz[v],v});
    return mex;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1;i<=n+1;++i) psa[i]={inf,-1};
    dfs(1,1);
    for (int i=n;i>=1;--i){
        psa[i]=min(psa[i],psa[i+1]);
    }
    for (int i=1;i<=q;++i){
        int x; cin >> x;
        if (x>n+1) cout << -1 << '\n';
        else cout << psa[x].id << '\n';
    }
}
