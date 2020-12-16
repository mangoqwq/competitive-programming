#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int seed=131, MAXN=1e5+1;

struct Edge{
    ll n, w;
    bool operator<(Edge x) const{ return w>x.w; }
};
vector<Edge> adj[MAXN];
ll dist[MAXN];
priority_queue<Edge> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int mod=n+1;
    for (int i=1;i<=m;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c*mod+1});
        adj[b].push_back({a,c*mod+1});
    }
    ms(dist,0x3f); dist[1]=0;
    pq.push({1,0});
    while (!pq.empty()){
        int v=pq.top().n; pq.pop();
        for (Edge to:adj[v]){
            if (dist[v]+to.w<dist[to.n]){
                dist[to.n]=dist[v]+to.w;
                pq.push({to.n,dist[to.n]});
            }
        }
    }
    if (dist[n]==0x3f3f3f3f3f3f3f3f) cout << -1 << '\n';
    else cout << dist[n]/mod << " " << dist[n]%mod << '\n';

}