#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=21;

vector<int> graph[MAXN];
bitset<MAXN> vis;
bool temp;

void dfs(int curr, int e){
    vis[curr]=1;
    for (int x:graph[curr]){
        if (x==e) temp=1;
        if (vis[x]) continue;
        dfs(x,e);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b,sa,sb;i<=m;++i){
        cin >> a >> b >> sa >> sb;
        if (sb>sa) swap(a,b);
        graph[a].push_back(b);
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        vis.reset(); temp=0;
        dfs(i,i);
        ans+=temp;
    }
    cout << ans << '\n';
}