#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<21);

bool ok[21][21];
int dp[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i){
        for (int k=0;k<n;++k){
            cin >> ok[i][k];
        }
    }
    dp[0]=1;
    for (int mask=0;mask<(1<<n);++mask){
        int cnt=__builtin_popcount(mask);
        for (int i=0;i<n;++i){
            if (!(1&(mask>>i))&&ok[i][cnt]) dp[mask+(1<<i)]=(dp[mask+(1<<i)]+dp[mask])%mod;
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}