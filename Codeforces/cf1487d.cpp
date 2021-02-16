#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (ll i=1;i<MAXN;++i) a[i]=(2*i+1)*(2*i+1);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        cout << (upper_bound(a,a+MAXN,2*n-1)-1)-a << '\n';
    }
}