#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

ll p2[MAXN], a[MAXN], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    p2[0]=1;
    for (int i=1;i<=n;++i) p2[i]=p2[i-1]*2%mod;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;++i){
        ans+=a[i]*p2[i-1];
        ans%=mod;
        ans-=a[i]*p2[n-i];
        ans=(ans%mod+mod)%mod;
    }
    cout << ans%mod << '\n';
}