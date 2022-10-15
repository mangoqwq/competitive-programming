#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e7+5;

ll arr[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, p, q; cin >> n >> p >> q;
    for (int i=n;i>=1;--i){
        ll a; cin >> a;
        arr[i]+=arr[i+1]; arr[i]%=mod;
        a+=arr[i]; a%=mod; 
        ans[i]=ans[i+1]+a; ans[i]%=mod;
        arr[i-1]-=a; arr[i-1]%=mod, arr[i-1]+=mod, arr[i-1]%=mod;
        arr[(i*p)/q]+=2*a; arr[(i*p)/q]%=mod;
    }
    for (int i=n;i>=1;--i) cout << ans[i]%mod << " ";
}