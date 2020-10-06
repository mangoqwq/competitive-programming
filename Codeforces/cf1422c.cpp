#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll p10[MAXN], arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    p10[0]=1;
    for (int i=1;i<MAXN;++i) p10[i]=(p10[i-1]*10)%mod;
    arr[0]=1;
    for (ll i=1;i<MAXN;++i) arr[i]=(p10[i]*(i+1))%mod, arr[i]+=arr[i-1];
    string s; cin >> s;
    int n=s.size(); s=" "+s;
    ll ans=0;
    for (ll i=1;i<=n;++i){
        ll val=s[i]-'0';
        ans+=val*arr[n-i-1]%mod;
        ans+=val*(((i)*(i-1))/2)%mod*p10[n-i]%mod;
        ans%=mod;
    }
    cout << ans << '\n';
}