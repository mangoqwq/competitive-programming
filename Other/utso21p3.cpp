#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN]; ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    cin >> a[1]; int idx=1; dp[1]=1;
    for (int i=2;i<=n;++i){
        cin >> a[i];
        if (a[i]>=a[idx]) dp[i]=dp[idx]*(i-idx+1)%mod, idx=i;
        else dp[i]=dp[i-1];
    }
    cout << dp[n] << '\n';
}