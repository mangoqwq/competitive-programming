#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[1001][1001];
int dp[1001][1001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int w,l; cin >> w >> l;
    for (int i=1;i<=l;++i){
        for (int k=1;k<=w;++k){
            cin >> a[i][k];
        }
    }
    memset(dp,0x3f,sizeof dp); dp[1][1]=a[1][1];
    int gc,gr; cin >> gc >> gr;
    for (int i=1;i<=l;++i){
        for (int k=1;k<=w;++k){
            dp[i][k]=min({dp[i][k],dp[i-1][k]+a[i][k],dp[i][k+1]+a[i][k],dp[i][k-1]+a[i][k]});
        }
        for (int k=w;k>=1;--k){
            dp[i][k]=min({dp[i][k],dp[i-1][k]+a[i][k],dp[i][k+1]+a[i][k],dp[i][k-1]+a[i][k]});
        }
    }
    cout << dp[gr+1][gc+1] << '\n';
}