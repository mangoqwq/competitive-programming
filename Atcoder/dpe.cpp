//Knapsack 2
#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    int N,W,a,b;
    cin >> N >> W;
    pair<ll,int> items[N];
    for (int i=0;i<N;++i){
        cin >> a >> b;
        items[i].first=a; items[i].second=b;
    }
    ll dp[(1000*N)+1];
    fill(dp, dp+(1000*N)+1,1000000001);
    for (int item=0;item<N;++item){
        for (int i=(1000*N);i>=0;--i){
            if (items[item].second<i){
                dp[i]=min(dp[i-items[item].second]+items[item].first,dp[i]);
            }
            else if (items[item].second==i){
                dp[i]=min(dp[i],items[item].first);
            }
        }
    }
    for (int i=(1000*N);i>=0;--i){
        if (dp[i]<=W){
            cout << i << '\n';
            break;
        }
    }
    




}