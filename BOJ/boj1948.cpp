#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e4+1;

int ord[MAXN], deg[MAXN], p;
struct Edge{ int to, w; };
vector<Edge> adj[MAXN], radj[MAXN];
int dist[MAXN], rdist[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b, c; cin >> a >> b >> c;
        deg[b]++;
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
    }
    int s, e; cin >> s >> e;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int v=q.front(); q.pop();
        ord[++p]=v;
        for (auto [to,w]:adj[v]){
            deg[to]--;
            if (deg[to]==0) q.push(to);
        }
    }
    for (int i=1;i<=n;++i){
        int v=ord[i];
        for (auto [to,w]:adj[v]) dist[to]=max(dist[to],dist[v]+w);
    }
    for (int i=n;i>=1;--i){
        int v=ord[i];
        for (auto [to,w]:radj[v]) rdist[to]=max(rdist[to],rdist[v]+w);
    }
    int cnt=0;
    for (int i=1;i<=n;++i){
        for (auto [to,w]:adj[i]) if (dist[i]+rdist[to]+w==dist[e]) cnt++;
    }
    cout << dist[e] << '\n' << cnt << '\n';
}