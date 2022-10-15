#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

priority_queue<ll> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, d, k, x; cin >> n >> d >> k >> x;
    for (int i=1;i<=n;++i){
        ll a; cin >> a; pq.push(a);
    }
    for (int i=1;i<=k;++i){
        ll v=pq.top(); pq.pop();
        pq.push(v*(100-x)/100);
    }
    ll p; cin >> p;
    cout << (pq.top()<p?"YES":"NO") << '\n';
}