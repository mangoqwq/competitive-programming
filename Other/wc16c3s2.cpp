#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll ans[MAXN], t[MAXN], mn, cp=1, ct;
struct Edge{
    int n; ll w;
    bool operator<(const Edge &other) const{ return w>other.w; }
};
vector<Edge> adj[MAXN];
priority_queue<Edge> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> t[i];
    for (int i=1;i<=m;++i){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    ms(ans,0x3f);
    ans[1]=0;
    mn=t[1];
    for (Edge x:adj[1]){
        pq.push(x);
    }
    while (!pq.empty()){
        int v=pq.top().n; ll w=pq.top().w; pq.pop();
        if (ans[v]!=inf) continue;
        if (cp<w) ct+=mn*(w-cp), cp=w;
        ans[v]=ct;
        mn=min(mn,t[v]);
        for (Edge x:adj[v]){
            if (ans[x.n]==inf) pq.push(x);
        }
    }
    cout << (ans[n]==inf?-1:ans[n]) << '\n';
}