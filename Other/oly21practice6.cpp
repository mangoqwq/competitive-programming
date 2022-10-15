#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Edge{
    ll n, w;
    bool operator<(const Edge &x) const{
        return w>x.w;
    }
};
vector<Edge> adj[MAXN];
ll n, m, c;
ll dist[MAXN], tot, ans=LLONG_MAX;
bool ins[MAXN];
priority_queue<Edge> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> c;
    for (int i=1;i<=m;++i){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        tot+=w;
    }
    ms(dist,0x3f);
    dist[1]=0, pq.push({1,0});
    while (!pq.empty()){
        int v=pq.top().n; pq.pop();
        for (Edge to:adj[v]){
            if (dist[v]+to.w<dist[to.n]){
                dist[to.n]=dist[v]+to.w;
                pq.push({to.n,dist[to.n]});
            }
        }
    }
    vector<pair<ll,ll>> vec;
    for (int i=1;i<=n;++i) vec.push_back({dist[i],i});
    sort(vec.begin(),vec.end());
    for (auto item:vec){
        ll v=item.second, x=item.first;
        ins[v]=1;
        for (auto to:adj[v]){
            if (ins[to.n]) tot-=to.w;
        }
        ans=min(ans,tot+x*c);
    }
    cout << ans << '\n';
}