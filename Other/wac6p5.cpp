#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

vector<int> adj[MAXN];
int src, vis[MAXN], p[MAXN];
vector<pair<int,int>> ans;

bool dfs(int v, int p){
    vector<int> curr;
    for (int to:adj[v]){
        if (to==p) continue;
        if (dfs(to,v)) curr.push_back(to);
    }
    while (curr.size()>=2){
        int a=curr.back(); curr.pop_back();
        int b=curr.back(); curr.pop_back();
        ans.push_back({a,b});
    }
    if (curr.size()==1&&p!=v){
        ans.push_back({curr.back(),p});
        return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    cout << ans.size() << '\n';
    for (auto x:ans) cout << x.first << " " << x.second << '\n';
}