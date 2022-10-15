#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll dist[MAXN];
struct Edge{
    ll v; ll w;
    bool operator<(const Edge &other) const{
        return w>other.w;
    }
};
vector<Edge> adj[MAXN];
priority_queue<Edge> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll h; cin >> h;
    ll a, b, c; cin >> a >> b >> c;
    if (c==1){ return cout << h << '\n', 0; }
    for (int i=0;i<c;++i) adj[i].push_back({(i+a)%c,a});
    for (int i=0;i<c;++i) adj[i].push_back({(i+b)%c,b});
    ms(dist,0x3f);
    dist[1]=1;
    pq.push({1,1});
    while (!pq.empty()){
        ll v, w;
        if (dist[pq.top().v]<pq.top().w){ pq.pop(); continue; }
        v=pq.top().v; pq.pop();
        for (Edge x:adj[v]){
            if (dist[x.v]>dist[v]+x.w){
                dist[x.v]=dist[v]+x.w;
                pq.push({x.v,dist[x.v]});
            }
        }
    }
    ll ans=0;
    for (int i=0;i<c;++i){
        if (h>=dist[i]) ans+=(h-dist[i])/c +1;
    }
    cout << ans << '\n';
}