#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

vector<int> arr;
int t,n,dp[101][101];
ll ans=0;

void solve(){
    ms(dp,0);
    for (int i=1;i<=n;++i){
        dp[i][i]=n*arr[i];
    }
    for (int len=1;len<n;++len){
        for (int l=1,r=l+len;r<=n;++l,++r){
            dp[l][r]=max(dp[l+1][r]+arr[l]*(n-len),dp[l][r-1]+arr[r]*(n-len));
        }
    }
    ans+=dp[1][n];
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t >> n;
    while (t--){
        arr.clear(); arr.push_back(0);
        for (int i=0,a;i<n;++i){ cin >> a; arr.push_back(a);}
        solve();
    }
    cout << ans << '\n';
}