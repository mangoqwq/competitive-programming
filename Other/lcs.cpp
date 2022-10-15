#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
int dp[1001][1001];
int a[1001];
int b[1001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int x,y; cin >> x >> y;
    for (int i=0;i<x;++i){
        cin >> a[i];
    }
    for (int i=0;i<y;++i){
        cin >> b[i];
    }
    for (int i=0;i<x+1;++i){
        for (int k=0;k<y+1;++k){
            if (i==0||k==0){
                dp[i][k]=0;
            }
            else if (a[i-1]==b[k-1]){
                dp[i][k]=dp[i-1][k-1]+1;
            }
            else{
                dp[i][k]=max(dp[i][k-1],dp[i-1][k]);
            }
        }
    }
    cout << dp[x][y] << '\n';
    
}