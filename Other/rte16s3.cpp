#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int L=13;
int n,q,l;
int in[6000];
int out[6000];
vector<pii> graph[6000];
ll d[6000];
int dist[6000][6000];
int up[6000][L+1];
int t=0;

void dfs(int node, int prev, ll dist){
    d[node]=dist;
    in[node]=++t;
    up[node][0]=prev;
    for (int i=1;i<=L;++i){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for (auto&&x:graph[node]){
        if (x.first==prev) continue;
        dfs(x.first,node,dist+x.second);
    }
    out[node]=++t;
}
bool is(int x,int y){
    return in[y]>=in[x] && out[y]<=out[x];
}
int lca(int x,int y){
    if (is(x,y)) return x;
    if (is(y,x)) return y;
    for (int i=L;i>=0;--i){
        if (!is(up[x][i],y)){
            x=up[x][i];
        }
    }
    return up[x][0];
}

ll query(int x,int y){
    return d[x]+d[y]-2*d[lca(x,y)];
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=0,a,b,w;i<n-1;++i){
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    dfs(0,0,0);
    cin >> q;
    int u,v;
    while (q--){
        cin >> u >> v;
        cout << query(u,v) << '\n';
    }
}
