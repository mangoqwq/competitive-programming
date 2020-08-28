#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=501;

int dp[MAXN][MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    int a;
    for (int i=0;i<=MAXN;++i){
        dp[i][0]=0x3f3f3f3f;
        dp[0][i]=0x3f3f3f3f;
    }
    dp[0][1]=0;
    dp[1][0]=0;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=m;++k){
            cin >> a;
            dp[i][k]=min(dp[i-1][k],dp[i][k-1])+a;
        }
    }
    cout << dp[n][m] << '\n';
}