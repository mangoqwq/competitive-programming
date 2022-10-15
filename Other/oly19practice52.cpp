#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e5+1;

struct Edge{ ll n, w; };
vector<Edge> graph[MAXN];
ll dist,far;

void dfs(int curr, int prev, ll d){
    if (d>dist) dist=d, far=curr;
    for (Edge x:graph[curr]){
        if (x.n==prev) continue;
        dfs(x.n,curr,d+x.w);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1,a,b,c;i<=n-1;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,1,0);
    dfs(far,far,0);
    cout << dist << '\n';
}