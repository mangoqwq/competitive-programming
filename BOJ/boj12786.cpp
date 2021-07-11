#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=50;

int last[MAXN], dp[MAXN];
bool hole[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int k; cin >> k;
    ms(dp,0x3f), dp[1]=0;
    for (int i=1;i<=n;++i){
        swap(dp,last);
        ms(dp,inf);
        int mn=*min_element(last+1,last+1+20);
        for (int j=1;j<=20;++j){
            dp[j]=min({last[j-1],last[j],last[j+1]});
            if (j%2==0) dp[j]=min(dp[j],last[j/2]);
            dp[j]=min(dp[j],mn+1);
        }
        for (int j=10;j<=20;++j){
            dp[20]=min(dp[20],last[j]);
        }
        int c; cin >> c;
        ms(hole,0);
        for (int j=1;j<=c;++j){
            int x; cin >> x;
            hole[x]=1;
        }
        for (int j=1;j<=20;++j) if (!hole[j]) dp[j]=inf;
    }
    int ans=*min_element(dp+1,dp+1+20);
    if (ans>k) cout << -1 << '\n';
    else cout << ans << '\n';
}