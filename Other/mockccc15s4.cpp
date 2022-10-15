#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5;

int d[MAXN], w[MAXN];
ll dp1[MAXN], dp2[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> d[i] >> w[i];
    for (int i=1;i<=n;++i){
        dp1[i]=min(dp1[i-1]+max(0,d[i]-w[i-1]),dp2[i-1]+d[i]);
        dp2[i]=min(dp1[i-1]+max(0,d[i]-w[i+1]-w[i-1]),dp2[i-1]+max(0,d[i]-w[i+1]));
    }
    cout << dp1[n] << '\n';
}