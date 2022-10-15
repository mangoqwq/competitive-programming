#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=301;

int dp[MAXN][MAXN];
string uwu; int n;

bool valid(int l, int r){
    return (uwu[l]=='('&&uwu[r]==')')||(uwu[l]=='['&&uwu[r]==']');
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> uwu;
    n=uwu.size();
    for (int i=0;i<=n;++i) dp[i][i]=1;
    for (int len=1;len<=n;++len){
        for (int l=0,r=l+len; r<n; l++, r++ ){
            dp[l][r]=min(dp[l+1][r]+1,dp[l][r-1]+1);
            if (valid(l,r)) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
            for (int i=l-1;i<r;++i){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
            }
            
        }
    }
    cout << dp[0][n-1] << '\n';
}   