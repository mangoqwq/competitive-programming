#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int cnt[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.length(); s=" "+s;
    for (int i=1;i<=n;++i) cnt[s[i]-'a']++;
    ll ans=1, tot=1;
    for (int i=25;i>=0;--i){
        ans=(ans+tot*cnt[i])%mod;
        tot=tot*(cnt[i]+1)%mod;
    }
    cout << ans << '\n';
}