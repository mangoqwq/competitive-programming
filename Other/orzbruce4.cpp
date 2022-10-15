#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

vector<int> adj[MAXN];
int dist[MAXN];
set<int> s;

void bfs(int src){
    queue<int> q;
    ms(dist,0x3f);
    dist[src]=0;
    q.push(src);
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (dist[to]>dist[v]+1){
                dist[to]=dist[v]+1;
                q.push(to);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=2;i<=n-1;++i) s.insert(i);
    bfs(1);
    for (int i=2;i<=n-1;++i) if (dist[i]>k) s.erase(i);
    bfs(n);
    for (int i=2;i<=n-1;++i) if (dist[i]>k) s.erase(i);
    int ans=1;
    for (int i=1;i<=s.size();++i) ans=ans*2%mod;
    cout << ans << '\n';
}