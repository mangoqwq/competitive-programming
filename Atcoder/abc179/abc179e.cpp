#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll vis[MAXN], tot[MAXN], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, x, m; cin >> n >> x >> m;
    tot[1]=x; vis[x]=1; ans=x;
    for (int i=2;i<=n;++i){
        x=x*x%m;
        if (vis[x]){
            ll idx=vis[x], per=i-vis[x];
            n=n-i+1;
            ans+=(tot[idx+per-1]-tot[idx-1])*(n/per);
            ans+=(tot[idx+n%per-1]-tot[idx-1]);
            break;
        }
        else vis[x]=i, ans+=x, tot[i]=tot[i-1]+x;
    }
    cout << ans << '\n';
}