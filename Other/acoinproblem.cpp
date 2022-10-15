#include <bits/stdc++.h>

using namespace std;
int coins[2000];
int dp[10001];
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
int ans[100001];


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    dp[0]=1;
    int n,v; cin >> n >> v;
    for (int i=0;i<n;++i){
        cin >> coins[i];
    }
    int used=0;
    int stuff, uwu,index;
    for (int i=1;i<v+1;++i){
        cin >> stuff >> uwu;
        pq.push({{uwu,stuff},i});
    }

    while (!pq.empty()){
        uwu=pq.top().first.first; stuff=pq.top().first.second; index=pq.top().second; pq.pop();
        while (used<uwu){
            for (int i=coins[used];i<10001;++i){
                if (dp[i-coins[used]]){
                    if (dp[i]==0){
                        dp[i]=dp[i-coins[used]]+1;
                    }
                    else{
                        dp[i]=min(dp[i],dp[i-coins[used]]+1);
                    }
                }
            }
            used++;
        }
        ans[index]=dp[stuff]-1;
    }
    for (int i=1;i<v+1;++i){
        cout << ans[i] << '\n';
    }
}