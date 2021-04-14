#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n;
vector<int> adj[MAXN];
ll k[MAXN], sz[MAXN], fact[MAXN], ans[MAXN];

void dfs(int v, int p){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
        fact[v]+=fact[to];
    }
    fact[v]+=sz[v];
}

void solve(int v, int p, ll cnt, ll top){
    ll tot=0, paths=1;
    ans[v]+=k[v]*(tot*cnt+paths*top); tot+=top, paths+=cnt;
    for (int to:adj[v]){
        if (to==p) continue;
        ans[v]+=k[v]*(sz[to]*tot+fact[to]*paths); tot+=fact[to], paths+=sz[to];
        solve(to,v,cnt+sz[v]-sz[to],(top+cnt)+(fact[v]-(fact[to]+sz[to])));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> k[i];
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    solve(1,1,0,0);
    cout << accumulate(ans+1,ans+1+n,0LL) << '\n';
}