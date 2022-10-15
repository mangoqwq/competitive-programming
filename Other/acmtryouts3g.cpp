#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int cost[MAXN], heavy[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void upd(int &a, int &b, int x){
    if (x>a) b=a, a=x;
    else if (x>b) b=x;
}

void dfs(int v){
    vis[v]=1;
    int b1=0, b2=0, tot=0;
    for (int u:adj[v]){
        if (vis[u]) continue;
        dfs(u);
        tot+=cost[u];
        upd(b1,b2,cost[u]-heavy[u]);
    }
    heavy[v]=tot-b1;
    cost[v]=tot-b1-b2+1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){    
        int n, m; cin >> n >> m;
        for (int i=1;i<=n;++i){
            cost[i]=heavy[i]=vis[i]=0;
            adj[i].clear();
        }
        for (int i=1,a,b;i<=m;++i){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=0;
        for (int i=1;i<=n;++i){
            if (vis[i]) continue;
            dfs(i);
            ans+=cost[i];
        }
        cout << n+ans-1 << '\n';
    }
}