#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<int> graph[21];
int visited[21];
bool cycle=false;

void dfs(int node,int dist){
    if (visited[node]){
        if (visited[node]==dist-6) cycle=true;
        return;
    }
    visited[node]=dist;
    for (auto&&x:graph[node]){
        dfs(x,dist+1);
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    dfs(1,0);
    if (cycle) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}