#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll diff[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, w; cin >> n >> w;
    for (int i=1;i<=n;++i){
        int s, t, p; cin >> s >> t >> p;
        diff[s]+=p, diff[t]-=p;
    }
    ll mx=diff[0];
    for (int i=1;i<MAXN;++i) mx=max(mx,diff[i]+=diff[i-1]);
    cout << (mx<=w?"Yes":"No") << '\n';
}