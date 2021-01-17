#include <bits/stdc++.h>

using namespace std;
vector<int> in[100001];
int dp[100001];

int dfs(int node){
    if (dp[node]!=-1){
        return dp[node];
    }
    int path=0;
    for (auto&&x:in[node]){
        path=max(dfs(x),path);
    }
    return dp[node]=path+1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m; cin >> n >> m;
    memset(dp,-1,sizeof dp);
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        in[b].push_back(a);
    }
    int uwu=0;
    for (int i=1;i<n+1;++i){
        uwu=max(uwu,dfs(i));
    }
    cout << uwu-1 << '\n';
}