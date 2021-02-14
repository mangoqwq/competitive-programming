#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=16;

ll a[MAXN][MAXN];
ll val[1<<MAXN], dp[1<<MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin >> a[i][j];
    for (int mask=0;mask<(1<<n);++mask)
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
                if ((1&(mask>>i))&&(1&mask>>j))
                    val[mask]+=a[i][j];
    for (int i=(1<<n)-1;i>=0;--i)
        for (int j=i;j>0;j=(j-1)&i)
            dp[i-j]=max(dp[i-j],dp[i]+val[j]);
    cout << dp[0] << '\n';
}