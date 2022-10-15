#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, m, q;
struct Edge{ int n, w; };
vector<Edge> adj[MAXN];
vector<ll> vec;
ll d[MAXN];
int last[MAXN], far;

void dfs(int v){
    if (d[v]>=d[far]) far=v;
    for (Edge to:adj[v]){
        if (to.n==last[v]) continue;
        last[to.n]=v;
        d[to.n]=d[v]+to.w;
        dfs(to.n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i=1;i<=m;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=1;i<=n;++i){
        if (last[i]) continue;
        far=i;
        last[i]=i, d[i]=0, dfs(i);
        last[far]=far, d[far]=0, dfs(far);
        if (q==1) vec.push_back(d[far]);
        else{
            ll rad=d[far];
            for (int i=far;;i=last[i]){
                rad=min(rad,max(d[i],d[far]-d[i]));
                if (last[i]==i) break;
            }
            vec.push_back(rad);
        }
    }
    if (q==1) cout << accumulate(vec.begin(),vec.end(),0LL)+vec.size()-1 << '\n';
    else{
        sort(vec.begin(),vec.end(),greater<ll>());
        cout << max(vec[0],vec[1]+1) << '\n';
    }
}