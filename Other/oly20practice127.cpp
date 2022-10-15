#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (1&e) ans*=b;
        b*=b, e>>=1;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll b, e; cin >> e >> b;
    cout << fpow(b,e) << '\n';
}