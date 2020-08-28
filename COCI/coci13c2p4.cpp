#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1501;

int dp[MAXN][MAXN]; //start,end
int dist[MAXN][MAXN],n;

int solve(int l, int r, int curr){
    if (l==n || r==n) return 0;
    if (dp[l][r]!=-1) return dp[l][r];
    return dp[l][r]=min(dist[curr][l]+solve(curr,r,curr+1),dist[curr][r]+solve(l,curr,curr+1));
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            cin >> dist[i][k];
        }
    }
    ms(dp,-1);
    cout << solve(1,1,1) << '\n';

}