#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];

int main(){
    int d,a,c; cin >> d >> a >> c;
    string x,y; cin >> x >> y;
    for (int i=0;i<=x.size();++i){
        for (int k=0;k<=y.size();++k){
            if (i==0){
                dp[i][k]=k*a;
            }
            else if (k==0){
                dp[i][k]=i*d;
            }
            else if (x[i-1]==y[k-1]){
                dp[i][k]=dp[i-1][k-1];
            }
            else{
                dp[i][k]=min(dp[i-1][k-1]+c,min(dp[i-1][k]+d,dp[i][k-1]+a));
            }
        }
    }
    cout << dp[x.size()][y.size()] << '\n';
}       