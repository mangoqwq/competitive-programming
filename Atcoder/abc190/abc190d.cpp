#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll n, ans=0;
void test1(ll i){
    if (n%i==0){
        if (n/i%2==1) ans++;
    }
}

void test2(ll i){
    if (2*n%i==0){
        if (2*n/i%2==1) ans++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (ll i=1;i*i<=n;++i){
        test1(i);
        if (i*i!=n) test1(n/i);
    }
    for (ll i=1;i*i<=2*n;++i){
        test2(i);
        if (i*i!=2*n) test2(2*n/i);
    }
    cout << ans << '\n';
}