#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e4+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll pre[MAXN],dp[MAXN],best,tmp; 

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> pre[i], pre[i]+=pre[i-1];
    pre[0]=-inf;
    for (int j=1;j<=k;++j){
        dp[j-1]=-inf; best=0;
        for (int i=j;i<=n;++i){
            tmp=dp[i];
            dp[i]=max(dp[i-1],best+pre[i]);
            best=max(best,tmp-pre[i]);
            //cout << dp[i] << " ";
        }
        //cout << '\n';
    }
    cout << dp[n] << '\n';
}