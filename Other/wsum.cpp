#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n), dp(n);
    ll tot=0;
    for (int i=0;i<n;++i){
        int x; cin >> x;
        a[i]=-2*x*(n-i);
        tot+=x*(n-i);
    }
    dp[0]=min(a[0],0LL);
    for (int i=1;i<n;++i) dp[i]=min({dp[i-1]+a[i],a[i],0LL});
    ll rem=*min_element(dp.begin(),dp.end());
    if (rem==0) rem=*min_element(a.begin(),a.end());
    cout << tot+rem << '\n';
}