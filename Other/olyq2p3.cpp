#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<12);

ll dp[MAXN][12][101],n;

inline ll solve(int prev, int r, int k){
    if (dp[prev][r][k]!=-1) return dp[prev][r][k];
    if (k==0) return 1;
    if (r>n||k<0) return 0; 
    ll &ans=dp[prev][r][k];
    ans=0;
    int mask;
    for (int i=0;i<(1<<(n+1));++i){
        bool flag=!(1&i);
        for (int j=1;j<=n;++j) if ((1&(i>>j))&(1&(prev>>j))) flag=0;
        for (int j=2;j<=n;++j) if ((1&(i>>j))&(1&(i>>(j-1)))) flag=0;
        if (!flag) continue;
        mask=0;
        for (int j=1;j<=n;++j) if (1&(i>>j)) mask|=(1<<(j-1))+(1<<(j))+(1<<(j+1));
        ans+=solve(mask,r+1,k-__builtin_popcount(i));
    }
    return ans;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int k; cin >> n >> k;
    ms(dp,-1);
    cout << solve(0,1,k) << '\n';
}