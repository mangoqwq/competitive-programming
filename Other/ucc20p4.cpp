#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5005;

int dp[MAXN];
int a[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=4;i<=n+3;++i) cin >> a[i];
    for (int i=4;i<=n+3;++i){
        dp[i]=min({dp[i-1]+a[i],dp[i-2]+a[i-1]+a[i]-min(a[i-1],a[i])/4,dp[i-3]+a[i-2]+a[i-1]+a[i]-min({a[i-2],a[i-1],a[i]})/2});
    }
    cout << dp[n+3] << '\n';
}