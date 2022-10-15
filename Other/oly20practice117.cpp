#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll l, r, a ,b;

ll cnt(ll x){
    return (r/x - (l-1)/x);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> r >> a >> b;
    cout << cnt(b)+cnt(a)-cnt(lcm(a,b)) << '\n';
}