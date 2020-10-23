#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int n, r, s, e;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int v, int p, int worst){
    if (v==e) cout << worst << '\n';
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v,min(worst,dist[to]));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ms(dist,0x3f);
    queue<int> q;
    for (int i=1,a;i<=r;++i) cin >> a, dist[a]=0, q.push(a);
    cin >> s >> e;
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (dist[v]+1<dist[to]){
                dist[to]=dist[v]+1;
                q.push(to);
            }
        }
    }
    dfs(s,s,dist[s]);
}