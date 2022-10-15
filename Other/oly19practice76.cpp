#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2001;

bool last[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int t=0;
    dp[0][0]=1;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        t+=x;
        swap(dp,last);
        for (int j=0;j<=t;++j){
            for (int k=0;k<=t;++k){
                dp[j][k]=last[j][k];
                if (j>=x) dp[j][k]|=last[j-x][k];
                if (k>=x) dp[j][k]|=last[j][k-x];
            }
        }
    }
    int ans=t;
    for (int i=1;i<=t;++i){
        for (int j=1;j<=t;++j){
            if (!dp[i][j]) continue;
            ans=min(ans,max({i,j,t-i-j}));
        }
    }
    cout << ans << '\n';
}