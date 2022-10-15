#include <bits/stdc++.h>

using namespace std;
int dp[200000];
bool weapon[200000];
vector<int> graph[200000];

int dfs(int node, int prev){
    int switches=0;
    int tempowo=0;
    if (weapon[prev]!=weapon[node]){
        tempowo=1;
    }
    if (dp[node]!=0){
        return dp[node]+tempowo;
    }
    for (auto&&x:graph[node]){
        switches=max(switches,dfs(x,node));
    }
    dp[node]=switches;
    return dp[node]+tempowo;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    bool a;
    for (int i=0;i<n;++i){
        cin >> a;
        weapon[i]=a;
    }
    for (int i=0,e,b;i<m;++i){
        cin >> e >> b;
        graph[b].push_back(e);
    }
    int swaps=0;
    for (int i=0;i<n;++i){
        swaps=max(swaps,dfs(i,i));
    }
    bool zero=false, one=false;
    for (int i=0;i<n;++i){
        if (dp[i]==swaps){
            if (weapon[i]==1){
                one=true;
            }
            else{
                zero=true;
            }
        }
    }
    if (one&&zero){
        swaps++;
    }
    cout << swaps << '\n';
}