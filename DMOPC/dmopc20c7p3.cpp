#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

int n, m, deg[MAXN], p[MAXN], ans[MAXN];
vector<int> radj[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> p[i];
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        radj[b].push_back(a);
        deg[a]++;
    }
    queue<int> q;
    for (int i=1;i<=n;++i){
        if (p[i]) deg[i]=min(deg[i],1);
        if (deg[i]==0) q.push(i);
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        ans[v]=1;
        for (int to:radj[v]){
            deg[to]--;
            if (deg[to]==0) q.push(to);
        }
    }
    for (int i=1;i<=n;++i) cout << ans[i] << (i==n?'\n':' ');
}