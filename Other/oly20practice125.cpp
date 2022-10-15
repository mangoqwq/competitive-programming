#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    int ans=0;
    for (int i=1;i<=n;++i){
        int c, v; cin >> c >> v;
        if (c<=t) ans=max(ans,v);
    }
    cout << ans << '\n';
}