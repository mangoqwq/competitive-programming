#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Edge{ int n; ll w; };
struct Node{
    ll d; int n;
    bool operator<(const Node &x)const{ return d>x.d; }
};
vector<Edge> graph[MAXN];
ll dist[11][11],dist2[MAXN];
map<int,int> key;
bool vis[MAXN];
int arr[12];

void go(int src){
    ms(dist2,0x3f); ms(vis,0);
    priority_queue<Node> pq;
    pq.push({0,src}); dist2[src]=0;
    while (!pq.empty()){
        ll curr=pq.top().n, d=pq.top().d; pq.pop();
        if (vis[curr]) continue;
        vis[curr]=1;
        for (Edge x:graph[curr]){
            if (d+x.w<dist2[x.n]) dist2[x.n]=d+x.w, pq.push({dist2[x.n],x.n});
        }
    }
    for (auto x:key){
        dist[key[src]][x.second]=dist2[x.first];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int k; cin >> k;
    for (int i=1,a;i<=k;++i){
        cin >> a;
        key[a]=i; arr[i]=i;
    }
    key[0]=0;
    for (auto x:key){
        go(x.first);
    }
    ll ans=LLONG_MAX;
    do{
        ll curr=0;
        for (int i=1;i<=k+1;++i){
            curr+=dist[arr[i]][arr[i-1]];
        }
        ans=min(ans,curr);
    } while (next_permutation(arr+1,arr+1+k));
    cout << ans << '\n';
}