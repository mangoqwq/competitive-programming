#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXT=5001,MAXN=501;

int dp[MAXN][MAXT],arr[MAXN];
bool vis[MAXN];

void back(int n, int t){
    if (n==0) return;
    if (dp[n][t]==n){
        vis[n]=1;
        t-=arr[n]; n--;
    }
    back(dp[n][t],t);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t, n; cin >> t >> n;
    ms(dp,-1);
    dp[0][0]=0;
    for (int i=1,a;i<=n;++i){
        cin >> a; arr[i]=a;
        dp[i][0]=0;
        for (int k=t;k>=0;--k){
            if (k>=a) if (dp[i-1][k-a]!=-1) dp[i][k]=i;
            if (dp[i-1][k]!=-1) dp[i][k]=dp[i-1][k];
        }
    }
    for (int i=t;i>=0;--i){
        if (dp[n][i]!=-1){
            back(n,i);
            break;
        }
    }
    int q1=0,q2=0;
    for (int i=1;i<=n;++i){
        if (vis[i]) cout << q1 << " ",q1+=arr[i];
        else cout << q2 << " ",q2+=arr[i];
    }
}