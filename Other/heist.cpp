#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll dp[MAXN][31];
deque<ll> arr;
int n, k;

void reset(){
    for (int i=1;i<=n;++i){
        for (int j=0;j<=k;++j) dp[i][j]=0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        arr.clear(); arr.push_back(0);
        for (int i=1,a;i<=n;++i){
            cin >> a; arr.push_back(a);
        }
        ll ans=0, res;
        if (k==n){
            for (int i=1;i<=n;++i) if (arr[i]>=0) ans+=arr[i];
            cout << ans << '\n';
            continue;
        }
        n--;
        for (int ii=1;ii<=k+1;++ii){
            res=arr[1];
            arr.pop_front(); arr.pop_front(); arr.push_front(0);
            reset();
            for (int i=1;i<=n;++i){
                for (int j=0;j<=k;++j) dp[i][0]=max(dp[i][0],dp[i-1][j]);
                for (int j=1;j<=k;++j){
                    dp[i][j]=dp[i-1][j-1]+arr[i];
                }
            }
            for (int j=0;j<=k;++j) ans=max(ans,dp[n][j]);
            arr.push_back(res);
        }
        cout << ans << '\n';
    }
}