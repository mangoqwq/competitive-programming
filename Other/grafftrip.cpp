#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<ll,ll> pll;
const int mod=1e9+7, seed=131, MAXN=1e4+1;

int n, m, x, y, s;
ll l;
struct Edge{ int n; ll w; };
vector<Edge> graph[MAXN], adj[105];
vector<ll> w;
map<int,int> id; 
int val[105], p;
ll dist[MAXN], dist2[105];
priority_queue<pll,vector<pll>,greater<pll>> pq;

void dij(int src){
    ms(dist,0x3f); dist[src]=0;
    pq.push({0,src});
    while (!pq.empty()){
        int curr=pq.top().second;
        ll d=pq.top().first; pq.pop();
        if (d>dist[curr]) continue;
        if (id.count(curr)) adj[id[src]].push_back({id[curr],d}), w.push_back(d);
        for (Edge x:graph[curr]){
            if (d+x.w<dist[x.n]){
                dist[x.n]=x.w+d;
                pq.push({dist[x.n],x.n});
            }
        }
    }
}

bool check(ll limit, int src=1){
    ms(dist2,0x3f); dist2[src]=0;
    while (!pq.empty()) pq.pop();
    pq.push({0,src});
    while (!pq.empty()){
        int curr=pq.top().second;
        ll d=pq.top().first; pq.pop();
        if (d>dist2[curr]) continue;
        if (curr==2) return d<=l;
        for (Edge x:adj[curr]){
            if (x.w>limit) continue;
            if (d+x.w<dist2[x.n]){
                dist2[x.n]=x.w+d;
                pq.push({dist2[x.n],x.n});
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x >> y;
    id[x]=++p; val[p]=x; id[y]=++p; val[p]=y;
    cin >> l;
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> s;
    for (int i=1,a;i<=s;++i){
        cin >> a;
        if (a==x||a==y) continue;
        id[a]=++p; val[p]=a;
    }
    for (auto x:id) dij(x.first);
    sort(w.begin(),w.end());
    int low=0, high=w.size()-1;
    while (low<high){
        int mid=low+high>>1;
        if (check(w[mid])) high=mid;
        else low=mid+1;
    }
    if (!check(w[low])) cout << -1 << '\n';
    else cout << w[low] << '\n';
}