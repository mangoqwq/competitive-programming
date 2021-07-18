#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3001;

ll last[MAXN], dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    dp[1]=1;
    for (int i=2;i<=n;++i){
        swap(last,dp);
        for (int j=2;j<=i;++j) last[j]=(last[j]+last[j-1])%mod;
        char c; cin >> c;
        for (int j=1;j<=i;++j){
            if (c=='<') dp[j]=last[j-1];
            if (c=='>') dp[j]=(last[i]-last[j-1]+mod)%mod;
        }
    }
    cout << accumulate(dp+1,dp+1+n,0LL)%mod << '\n';
}
