#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=1001;

int cnt[MAXN], fix[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    fill(cnt+1,cnt+1+n,k);
    for (int i=1;i<=k;++i){
        char c; int x; cin >> c >> x;
        if (c=='R'){
            for (int j=x+1;j<=n;++j) if (!fix[j]) cnt[j]--;
        }
        if (c=='L'){
            for (int j=x-1;j>=1;--j) if (!fix[j]) cnt[j]--;
        }
        fix[x]=1;
    }
    ll ans=1;
    for (int i=1;i<=n;++i){
        if (fix[i]) continue;
        ans=ans*cnt[i]%mod;
    }
    cout << ans << '\n';
}
