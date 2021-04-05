#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e4+1;

ll last[MAXN], dp[MAXN], a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    dp[0]=a[1]<=0;
    for (int i=2;i<=n;++i){
        swap(dp,last); ms(dp,0);
        if (a[i]==0) dp[0]=(last[0]+last[1])%mod;
        else if (a[i]!=-1) dp[a[i]]=(last[a[i]-1]+last[a[i]]+last[a[i]+1])%mod;
        else{
            dp[0]=(last[0]+last[1])%mod;
            for (int j=1;j<=n;++j){
                dp[j]=(last[j-1]+last[j]+last[j+1])%mod;
            }
        }
    }
    cout << dp[0] << '\n';
}