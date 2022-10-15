#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[1010][1010];


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    for (int i=0;i<=n;++i){
        for (int k=0;k<=m;++k){
            //cout << i << " " << k << '\n';
            if (i==0){
                dp[i][k]=(k+2)/3;
                continue;
            }
            if (k==0){
                dp[i][k]=(i+2)/3;
                continue;
            }
            if (a[i-1]==b[k-1]){
                dp[i][k]=dp[i-1][k-1];
                continue;
            }
            dp[i][k]=min({dp[max(0,i-3)][k]+1,dp[max(0,i-2)][k]+1,dp[i-1][k]+1,dp[i][k-1]+1,dp[i][max(0,k-2)]+1,dp[i][max(k-3,0)]+1,dp[i-1][k-1]+1});
        }
    }
    for (int i=0;i<=n;++i){
        for (int k=0;k<=m;++k){
            //cout << dp[i][k] << " ";
        }
        //cout << '\n';
    }
    cout << dp[n][m] << '\n';
}