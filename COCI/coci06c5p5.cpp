#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=105;

int dp[2][MAXN][MAXN]; // 0 is first, 1 is second
deque<int> arr;
int n;

void solve(){
    ms(dp,0);
    for (int i=1;i<n;++i){
        dp[0][i][i]=arr[i-1];
        dp[1][i][i]=-arr[i-1];
    }
    for (int len=2;len<n;++len){
        for (int l=1,r=len;r<n;++l,++r){
            dp[0][l][r]=max(dp[1][l][r-1]+dp[0][r][r],dp[1][l+1][r]+dp[0][l][l]);
            dp[1][l][r]=min(dp[0][l][r-1]+dp[1][r][r],dp[0][l+1][r]+dp[1][l][l]);
        }
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a; a%=2;
        arr.push_back(a);
    }
    int ans=0;
    for (int i=1,a;i<=n;++i){
        a=arr.front(); arr.pop_front();
        solve();
        if (a+dp[1][1][n-1]>0) ans++;
        arr.push_back(a);
    }
    cout << ans << '\n';
}