#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        for (ll i=n;;++i){
            string s=to_string(i);
            ll val=0;
            for (char x:s) val+=x-'0';
            if (gcd(i,val)>1){ cout << i << '\n'; break; }
        }
    }
}