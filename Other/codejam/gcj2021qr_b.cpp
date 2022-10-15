#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int dp[MAXN][2];

int solve(){
    int cj, jc; cin >> cj >> jc;
    string s; cin >> s;
    int n=s.size(); s=" "+s;
    dp[1][0]=dp[1][1]=inf;
    if (s[1]=='C'||s[1]=='?') dp[1][0]=0;
    if (s[1]=='J'||s[1]=='?') dp[1][1]=0;
    for (int i=2;i<=n;++i){
        if (s[i]=='C'){
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]+jc);
            dp[i][1]=inf;
        }
        if (s[i]=='J'){
            dp[i][0]=inf;
            dp[i][1]=min(dp[i-1][0]+cj,dp[i-1][1]);
        }
        if (s[i]=='?'){
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]+jc);
            dp[i][1]=min(dp[i-1][0]+cj,dp[i-1][1]);
        }
    }
    return min(dp[n][0],dp[n][1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int c=1;c<=t;++c){
        cout << "Case #" << c << ": " << solve() << '\n';
    }
}