#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int n=s.size(), k=min(s.size(),t.size()), ans=n;
    ll hsh1=0, hsh2=0, p=1;
    for (int i=0;i<k;++i){
        hsh1=(hsh1+s[--n]*p)%mod;
        hsh2=(hsh2*seed+t[i])%mod;
        if (hsh1==hsh2) ans=n;
        p=p*seed%mod;
    }
    cout << s.substr(0,ans) << t << '\n';
}