#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4001;

int h[MAXN];
ll dp[MAXN], last[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    cin >> h[1];
    dp[1]=1;
    for (int i=2;i<=n;++i){
        cin >> h[i];
        swap(dp,last);
        for (int j=1;j<=i-1;++j) last[j]=(last[j-1]+last[j])%mod;
        for (int j=1;j<=i;++j){
            if (h[i]<h[i-1]){
                dp[j]=(last[i-1]-last[j-1]+mod)%mod;
            }
            if (h[i]==h[i-1]){
                dp[j]=last[i-1];
            }
            if (h[i]>h[i-1]){
                dp[j]=last[j-1];
            }
        }
    }
    cout << accumulate(dp+1,dp+1+n,0LL)%mod << '\n';
}
