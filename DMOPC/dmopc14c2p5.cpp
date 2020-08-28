#include <bits/stdc++.h>

using namespace std;
int degree[1000001];
double dp[1000001];
vector<int> graph[1000001];
vector<int> in[1000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    cout.setf(ios::fixed);
    int n, m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        in[b].push_back(a);
        degree[a]++;
    }
    dp[1]=1.0;
    for (int i=2;i<n+1;++i){
        for (auto&&x:in[i]){
            dp[i]+=(1/(double)degree[x])*dp[x];
        }
    }
    for (int i=1;i<n+1;++i){
        if (degree[i]==0){
            cout << setprecision(15) << dp[i] << '\n';
        }
    }
}