#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101,MAXK=1e4+1;

int dp[MAXN][MAXK],arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp,0x3f);
    int n,l,r,b; cin >> n >> l >> r >> b;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int items=r-l+1;
    dp[0][0]=0;
    for (int i=1;i<=n;++i){
        for (int j=items;j>=1;--j){
            int cost=abs(i-(l+j-1));
            for (int k=cost;k<=b;++k){
                dp[j][k]=min(dp[j][k],dp[j-1][k-cost]+arr[i]);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for (int i=0;i<=b;++i) ans=min(ans,dp[items][i]);
    cout << ans << '\n';
}