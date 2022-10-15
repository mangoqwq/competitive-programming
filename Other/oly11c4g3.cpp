#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int n, k, to, sz, ans[MAXN][22];
vector<int> adj[MAXN];

void dfs1(int v, int p){
    for (int to:adj[v]){
        if (to==p) continue;
        dfs1(to,v);
        for (int i=1;i<=k;++i) ans[v][i]+=ans[to][i-1];
    }
}

void dfs2(int v, int p){
    for (int i=k;i>=2;--i){
        if (!p) break;
        ans[v][i]+=ans[p][i-1]-ans[v][i-2];
    }
    ans[v][1]+=ans[p][0];
    for (int to:adj[v]){
        if (to==p) continue;
        dfs2(to,v);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1;i<=n;++i) cin >> ans[i][0];
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1;i<=n;++i){
        int sum=0;
        for (int j=0;j<=k;++j) sum+=ans[i][j];
        cout << sum << '\n';
    }
}