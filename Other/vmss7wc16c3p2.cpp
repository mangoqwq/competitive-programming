#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int node){
    vis[node]=1;
    for (int x:graph[node]){
        if (!vis[x]) dfs(x);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,s,e; cin >> n >> m >> s >> e;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(s);
    cout << (vis[e]?"GO SHAHIR!":"NO SHAHIR!") << '\n';

}