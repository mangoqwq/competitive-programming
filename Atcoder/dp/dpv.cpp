#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int seed=131, MAXN=1e5+1;

int n;
ll mod, down[MAXN], ans[MAXN];
vector<int> adj[MAXN];
vector<ll> pre[MAXN], suf[MAXN];

int dfs1(int v, int p){
    down[v]=1; pre[v].push_back(1);
    for (int to:adj[v]){
        if (to==p) continue;
        down[v]*=(dfs1(to,v)+1); down[v]%=mod;
        pre[v].push_back(down[v]);
    }
    suf[v].push_back(1);
    for (int i=adj[v].size()-1;i>=0;--i){
        int to=adj[v][i];
        if (to==p) continue;
        suf[v].push_back((down[to]+1)*suf[v].back()%mod);
    }
    suf[v].push_back(1);
    reverse(suf[v].begin(),suf[v].end());
    return down[v];
}

void dfs2(int v, int p, ll up){
    ans[v]=down[v]*up; ans[v]%=mod;
    int cnt=0;
    for (int to:adj[v]){
        if (to==p) continue;
        cnt++;
        dfs2(to,v,up*pre[v][cnt-1]%mod*suf[v][cnt+1]%mod+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mod;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,1); dfs2(1,1,1);
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
}