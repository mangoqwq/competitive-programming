#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll s, p; cin >> s >> p;
    bool ans=0;
    for (ll i=1;i<=1000000;++i){
        if (i*(s-i)==p) ans=1;
    }
    cout << (ans?"Yes":"No") << '\n';
}