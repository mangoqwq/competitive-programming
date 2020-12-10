#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=351;

ll last[MAXN], dp[MAXN], fact[MAXN], c[MAXN][MAXN];

ll fpow(ll b, int e){
    ll ans=1;
    while (e){
        if (1&e) ans*=b, ans%=mod;
        e>>=1, b*=b, b%=mod;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fact[0]=1;
    for (int i=1;i<=n;++i) fact[i]=fact[i-1]*i%mod;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=i;++j)
            c[i][j]=fact[i]*fpow(fact[j],mod-2)%mod*fpow(fact[i-j],mod-2)%mod;
    dp[0]=1;
    for (int i=1;i<=n;++i){
        swap(last,dp); ms(dp,0);
        for (int j=0;j<=n;++j){
            for (int k=0;k<=j;++k){
                if (k!=i) dp[j]+=last[j-k]*c[j][k], dp[j]%=mod;
            }
        }
    }
    cout << (fpow(n,n)-dp[n]+mod)%mod << '\n';
}