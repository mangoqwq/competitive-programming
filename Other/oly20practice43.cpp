#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Dist{ 
    ll h,d,n;
    bool operator<(const Dist &a) const{ return tie(d,h,n)>tie(a.d,a.h,a.n); }
};
struct Edge{ ll n,d; };
ll dist[MAXN];
vector<Edge> graph[MAXN];
ll h[MAXN];
bool vis[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,sh; cin >> n >> m >> sh;
    for (int i=1;i<=n;++i) cin >> h[i];
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<Dist> pq; ms(dist,0x3f); dist[1]=0;
    pq.push({sh,0,1}); Dist curr; ll endt,endh;
    while (!pq.empty()){
        curr=pq.top(); pq.pop();
        if (vis[curr.n]) continue;
        vis[curr.n]=1;
        if (curr.n==n){ cout << h[n]-curr.h+curr.d << '\n'; return 0; }
        for (Edge x:graph[curr.n]){
            if (h[curr.n]<x.d) continue;
            else if (curr.h-x.d>h[x.n]) endt=curr.h-h[x.n], endh=h[x.n];
            else if (curr.h-x.d<0) endt=2*x.d-curr.h, endh=0;
            else endt=x.d, endh=curr.h-x.d;
            endt+=curr.d;

            if (dist[x.n]>endt) dist[x.n]=endt, pq.push({endh,endt,x.n});
        }
    }
    cout << -1 << '\n';
}