#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

bool isprime(ll n){
    for (ll i=2;i*i<=n;++i){
        if (n%i==0) return 0;
    }
    return 1;
}

void solve(){
    ll n; cin >> n;
    ll lo=2, hi=1e9, mid, p1, p2, ans=0;
    while (lo<hi){
        mid=(lo+hi+1)>>1;
        p1=mid, p2=mid+1;
        while (!isprime(p1)) p1--;
        while (!isprime(p2)) p2++;
        if (p1*p2>n) hi=mid-1;
        else lo=mid, ans=max(ans,p1*p2);
    }
    p1=lo, p2=lo+1;
    while (!isprime(p1)) p1--;
    while (!isprime(p2)) p2++;
    cout << p1*p2 << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}