#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int inf=0x3f3f3f3f, MAXN=1e6+1;

// 1/15

ll a[MAXN];

ll fpow(ll b, ll e, ll m){
    if (b==0&&e==0) return 0;
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%m;
        e>>=1, b=b*b%m;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> a[i]; a[1]%=m;
    }
    for (int i=n-1;i>=1;--i){
        a[i]=fpow(a[i],a[i+1],m-i+1);
    }
    cout << a[1]%m << '\n';
}