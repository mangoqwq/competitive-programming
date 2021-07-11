#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2005;

int n;
int d[MAXN], vis[MAXN];
vector<int> nd[MAXN];
set<int> adj[MAXN];

void guess(int v){
    cout << "? " << v << '\n';
    cout.flush();
    for (int i=1;i<=n;++i) cin >> d[i];
    for (int i=1;i<=n;++i) nd[i].clear();
    for (int i=1;i<=n;++i) nd[d[i]].push_back(i);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    queue<int> q; q.push(1); vis[1]=1;
    while (!q.empty()){
        int v=q.front(); q.pop();
        guess(v);
        for (int to:nd[1]){
            adj[v].insert(to);
            adj[to].insert(v);
        }
        if (nd[2].size()<=nd[1].size()){
            for (int to:nd[2]) if (!vis[to]) q.push(to), vis[to]=1;
            for (int to:nd[1]) vis[to]=1;
        }
        else{
            for (int to:nd[1]) if (!vis[to]) q.push(to), vis[to]=1;
        }
    }
    cout << '!' << '\n';
    for (int i=1;i<=n;++i){
        for (int to:adj[i]){
            if (to<=i) continue;
            cout << i << " " << to << '\n';
        }
    }
    cout.flush();
}