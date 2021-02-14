#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXM=101, MAXK=501;

ll arr[MAXM], dp[2][MAXK];

ll eval(ll n, ll k){
    k++;
    ll a=n-(n/k)*k, b=n/k;
    return a*(b+1)*(b+2)/2+(k-a)*(b)*(b+1)/2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        arr[a]++;
    }
    ms(dp,0x3f); dp[0][0]=0;
    for (int i=1;i<=m;++i){
        ms(dp[i%2],0x3f);
        for (int j=0;j<=k&&j<=arr[i];++j){
            for (int x=0;x+j<=k;++x){   
                dp[i%2][x+j]=min(dp[i%2][x+j],dp[(i-1)%2][x]+eval(arr[i],j));
            }
        }
    }
    cout << *min_element(dp[m%2]+0,dp[m%2]+1+k) << '\n';
}