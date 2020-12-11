#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=40;

ll arr[MAXN];
vector<ll> a1, a2;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, t; cin >> n >> t;
    for (int i=0;i<n;++i) cin >> arr[i];
    for (int mask=0;mask<(1<<20);++mask){
        ll v1=0, v2=0;
        for (int i=0;i<20;++i) if (1&(mask>>i)) v1+=arr[i];
        for (int i=20;i<40;++i) if (1&(mask>>i-20)) v2+=arr[i];
        if (v1<=t) a1.push_back(v1);
        if (v2<=t) a2.push_back(v2);
    }
    a2.push_back(0);
    a1.push_back(0);
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    ll ans=0;
    for (ll v1:a1){
        ans=max(ans,v1+*(--upper_bound(a2.begin(),a2.end(),t-v1)));
    }
    cout << ans << '\n';
}