#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a, b, c; cin >> a >> b >> c;
    ll d=b-a, e=c-b;
    if (d>=e){
        cout << d-e << '\n';
    }
    else{
        ll ans=0;
        if ((d+e)%2) ans++, e++;
        cout << (e-d)/2+ans << '\n';
    }
}
