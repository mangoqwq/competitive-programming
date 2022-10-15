#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a, b; cin >> a >> b;
        ll g=gcd(a,b);
        a/=g, b/=g;
        int two=0, five=0;
        while (b%2==0) two++, b/=2;
        while (b%5==0) five++, b/=5;
        if (b!=1) cout << -1 << '\n';
        else cout << max(two,five) << '\n';
    }
}
