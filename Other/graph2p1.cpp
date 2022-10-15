#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

vector<int> graph[MAXN], vec;
bool vis[MAXN];

void dfs(int curr){
    vec.push_back(curr); vis[curr]=1;
    for (int x:graph[curr]){
        if (vis[x]) continue;
        dfs(x);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    bool a;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> a;
            if (a) graph[i].push_back(j);
        }
    }
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        dfs(i);
        sort(vec.begin(),vec.end());
        for (int x:vec) cout << x << " ";
        cout << '\n';
        vec.clear();
    }
}