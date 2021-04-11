#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e4+1;

int last[MAXN], dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int e; cin >> e;
    ms(dp,-0x3f), iota(dp,dp+e,0);
    for (int i=2;i<=n;++i){
        swap(last,dp);
        int a, b; cin >> a >> b;
        int pre=*max_element(last,last+a);
        for (int j=0;j<b;++j) dp[j]=max(j+pre,last[j+a]);
        for (int j=b;j<a+b;++j) dp[j]=b+last[j-b];
        for (int j=a+b;j<MAXN;++j) dp[j]=last[j];
    }
    cout << *max_element(dp,dp+MAXN) << '\n';
}