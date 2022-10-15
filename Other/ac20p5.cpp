#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e5+1;

vector<int> adj[MAXN];
int diff[MAXN], p[MAXN], sz[MAXN];
map<int,int> m;
vector<pair<int,int>> ans;

int dfs(int v){
    sz[v]=1;
    for (int to:adj[v]){
        if (to==p[v]) continue;
        sz[v]+=dfs(to);
    }
    return sz[v];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=2;i<=n;++i){
        int a; cin >> a;
        adj[a].push_back(i);
        p[i]=a;
    }
    dfs(1);
    for (int i=1;i<=n;++i){
        diff[sz[i]-1]++;
        for (int c:adj[i]) diff[sz[c]]--; 
    }
    for (int i=n-1;i>=1;--i) diff[i]+=diff[i+1];
    for (int i=2;i<=n;++i){
        int tmp=i;
        for (int j=2;j*j<=i;++j){
            while (tmp%j==0) tmp/=j, m[j]+=diff[i];
        }
        if (tmp!=1) m[tmp]+=diff[i];
    }
    for (auto x:m) if (x.second!=0) ans.push_back(x);
    cout << ans.size() << '\n';
    for (auto x:ans) cout << x.first << " " << x.second << '\n';
}