#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

unordered_map<ll,int> dp;

int solve(ll n){
    if (dp.count(n)) return dp[n];
    for (int i=1;;++i){
        for (int d=i;d<=3*i;++d){
            if ((n-d)%10) continue;
            if (solve((n-d)/10)<=i) return dp[n]=i;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        dp.clear(); dp[0]=0;
        cout << solve(n) << '\n';
    }
}
