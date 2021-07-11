#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a=0, ab=0, abc=0;
    string s; cin >> s;
    for (char c:s){
        if (c=='a') a=(a*2+1)%mod;
        else if (c=='b') ab=(ab*2+a)%mod;
        else if (c=='c') abc=(abc*2+ab)%mod;
    }
    cout << abc << '\n';
}