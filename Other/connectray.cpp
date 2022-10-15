#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=4e5+1;

vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int curr){
    vis[curr]=1;
    for (int x:graph[curr]){
        if (vis[x]) continue;
        dfs(x);
    }
}

void Add(int a, int b){
    if (vis[b]) return;
    graph[a].push_back(b);
    if (vis[a]) dfs(b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,q; cin >> n >> m >> q;
    vis[1]=1;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        Add(a,b);
    }
    char cmd;
    for (int i=1,a,b;i<=q;++i){
        cin >> cmd;
        if (cmd=='+'){
            cin >> a >> b;
            Add(a,b);
        }
        if (cmd=='?'){
            cin >> a;
            cout << (vis[a]?"YES":"NO") << '\n';
        }
    }
}