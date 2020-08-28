#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=150'001;

int n, arr[3][MAXN],dp[3][MAXN];

int solve(vector<int> uwu){
    int a=uwu[0],b=uwu[1],c=uwu[2];
    ms(dp,0x3f);
    dp[a][0]=0;
    for (int i=1;i<=n;++i){ dp[a][i]=dp[a][i-1]+arr[a][i]; }
    for (int i=2;i<=n;++i){ dp[b][i]=min(dp[b][i-1],dp[a][i-1])+arr[b][i]; }
    for (int i=3;i<=n;++i){ dp[c][i]=min(dp[c][i-1],dp[b][i-1])+arr[c][i]; }
    return dp[c][n];
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<=2;++i){ for (int k=1;k<=n;++k) { cin >> arr[i][k]; }}
    vector<int> permu={0,1,2}; int ans=0x3f3f3f3f;
    for (int i=0;i<6;++i){
        ans=min(ans,solve(permu));
        next_permutation(permu.begin(),permu.end());
    }
    cout << ans << '\n';

}