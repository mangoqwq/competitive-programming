#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int inf=0x3f3f3f3f, MAXN=1e4+1;

ll dp[MAXN], last[MAXN], mod;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.size(); s=" "+s;
    cin >> mod;
    fill(dp,dp+1+n,1);
    for (int i=1;i<=n;++i){
        swap(dp,last), dp[0]=1;
        for (int j=1;j<=n;++j){
            dp[j]=dp[j-1]+last[j]-last[j-1];
            if (s[i]==s[j]) dp[j]+=last[j-1];
            dp[j]=(dp[j]%mod+mod)%mod;
        }
    }
    cout << dp[n] << '\n';
}