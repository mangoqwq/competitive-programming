#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=8641;

double dp[MAXN], val[101]; int ti[101], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i=1;i<=n;++i) cin >> ti[i];
    for (int i=1,a;i<=m;++i){
        cin >> a;
        if (a==0) ans++;
        for (int j=1,b;j<=a;++j) cin >> b, val[b]+=1.0/a;
    }
    for (int i=1;i<=n;++i){
        for (int j=t;j>=ti[i];--j) dp[j]=max(dp[j],dp[j-ti[i]]+val[i]);
    }
    printf("%.2f",dp[t]+ans);
}