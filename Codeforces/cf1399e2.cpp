#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Edge{ int n; ll w; int id, c; };
vector<Edge> graph[MAXN];
ll cnt[MAXN],val[MAXN]; int cost[MAXN];

int dfs(int curr, int prev){
    if (graph[curr].size()==1) cnt[prev]=1;
    for (Edge x:graph[curr]){
        if (x.id==prev) continue;
        cnt[prev]+=dfs(x.n,x.id);
    }
    return cnt[prev];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,s; cin >> n >> s;
        for (int i=1;i<=n;++i) graph[i].clear(),cnt[i]=val[i]=0;
        for (int i=1,a,b;i<n;++i){
            cin >> a >> b >> val[i] >> cost[i];
            graph[a].push_back({b,val[i],i,cost[i]});
            graph[b].push_back({a,val[i],i,cost[i]});
        }
        dfs(1,0);
        ll tot=0,ans=0; set<pll> s1,s2;
        for (int i=1;i<n;++i){
            tot+=cnt[i]*val[i];
            if (cost[i]==1) s1.insert({val[i]*cnt[i]-(val[i]/2)*cnt[i],i});
            if (cost[i]==2) s2.insert({val[i]*cnt[i]-(val[i]/2)*cnt[i],i});
        }
        while (tot>s){
            
        }
        cout << ans << '\n';
    }
}