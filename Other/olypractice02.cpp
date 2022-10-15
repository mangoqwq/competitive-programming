//Knapsack 3
#include <bits/stdc++.h>
#include <vector>
#include <utility> 

using namespace std;
typedef long long ll;
ll dp[100001];

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    int N,W,a;
    ll b;
    cin >> N >> W;
    for (int _=0;_<N;++_){
        cin >> a >> b;
        for (int i=W;i>a-1;--i){
            dp[i]=max(dp[i],dp[i-a]+b);
        }
    }

    /*for (int i=1;i<W;++i){
        cout << dp[i] << " ";
    }*/
    cout << dp[W] << '\n';




}