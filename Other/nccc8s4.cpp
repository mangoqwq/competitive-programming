#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=53;

map<int,set<int>> adj; set<int> src;
set<int> vis;
int ans=0;

void dfs(int v, int src){
    vis.insert(v);
    for (int to:adj[v]){
        if (!to) continue;
        if (to==src) ans=1;
        else if (!vis.count(to)) dfs(to,src);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[-a].insert({b,c,d});
        adj[-b].insert({a,c,d});
        adj[-c].insert({a,b,d});
        adj[-d].insert({a,b,c});
        src.insert(a);
        src.insert(b);
        src.insert(c);
        src.insert(d);
    }
    for (int s:src){
        if (s) vis.clear(), dfs(s,s);
    }
    cout << ans << '\n';
}