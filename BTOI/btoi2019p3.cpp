#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Edge{ int x,id; ll w; };
vector<Edge> graph[MAXN];
bool shop[MAXN]; ll dist[MAXN],ans;

void solve(int curr, int prev, ll d, int no){
    if (shop[curr]) ans=min(ans,d);
    dist[curr]=d;
    for (Edge x:graph[curr]){
        if (x.id==no||x.x==prev) continue;
        solve(x.x,curr,d+x.w,no);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,s,q,e; cin >> n >> s >> q >> e;
    for (int i=1,a,b,c;i<=n-1;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,i,c});
        graph[b].push_back({a,i,c});
    }
    for (int i=1,a;i<=s;++i) cin >> a, shop[a]=1;
    for (int i=1,x,a;i<=q;++i){
        cin >> x >> a; ans=LLONG_MAX;
        for (int j=1;j<=n;++j) dist[j]=-1;
        solve(a,a,0,x);
        if (dist[e]!=-1) cout << "escaped" << '\n';
        else if (ans==LLONG_MAX) cout << "oo" << '\n';
        else cout << ans << '\n';
    }
}