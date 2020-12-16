#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define tri(x) ((x)*(x+1)/2)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, ans=0; cin >> n;
    for (ll i=1;i<=n;++i){
        ans+=tri(n/i)*i;
    }
    cout << ans << '\n';
}