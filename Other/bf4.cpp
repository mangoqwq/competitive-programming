#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;
const int seed=131;

ll p, hsh[MAXN];
ll match;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int n=s.size(), m=t.size();
    s=" "+s, t=" "+t;
    p=1;
    for (int i=1;i<=m;++i) p=p*seed%mod;
    for (int i=1;i<=n;++i) hsh[i]=(hsh[i-1]*seed+s[i])%mod;
    for (int i=1;i<=m;++i) match=(match*seed+t[i])%mod;
    for (int i=m;i<=n;++i){
        ll curr=(hsh[i]-hsh[i-m]*p%mod+mod)%mod;
        if (curr==match) return cout << i-m << '\n', 0;
    }
    cout << -1 << '\n';
}