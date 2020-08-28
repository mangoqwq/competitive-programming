#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

//Interval DP

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<ll,ll> pii;
const int mod=1e9+7,seed=131,MAXN=401;
ll dp[MAXN][MAXN];
ll pre[MAXN];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ms(dp,0x3f);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> pre[i];
        pre[i]+=pre[i-1];
        dp[i][i]=0;
    }
    for (int len=2;len<=n;++len){
        for (int l=1,r=l+len-1;r<=n;++l,++r){
            for (int x=l;x<r;++x){
                dp[l][r]=min(dp[l][r],dp[l][x]+dp[x+1][r]);
            }
            dp[l][r]+=pre[r]-pre[l-1];
        }
    }
    cout << dp[1][n] << '\n';
}