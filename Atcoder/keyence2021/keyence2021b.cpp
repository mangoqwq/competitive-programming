#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

multiset<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        s.insert(a);
    }
    ll ans=0;
    for (int i=1;i<=k;++i){
        for (int j=0;j<=n;++j){
            if (s.find(j)!=s.end()){
                s.erase(s.lower_bound(j));
            }
            else{ ans+=j; break; }
        }
    }
    cout << ans << '\n';
}