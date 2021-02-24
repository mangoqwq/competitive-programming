#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, s1; cin >> s;
    int n=s.size(); s=" "+s;
    ll ans=0, cl=0, cm=0, cs=0, ccm=0, ccs=0;
    for (int i=1;i<=n;++i){
        if (s[i]=='L') cl++;
        else if (s[i]=='M') cm++;
        else cs++;
    }
    for (int i=1;i<=cl;++i){
        if (s[i]=='M') ccm++, ans++;
        else if (s[i]=='S') ccs++, ans++;
    }
    for (int i=cl+1;i<=cl+cm;++i){
        if (s[i]=='L'){
            if (ccm) ccm--;
            else ans++;
        }
        else if (s[i]=='S') ans++;
    }
    cout << ans << '\n';
}