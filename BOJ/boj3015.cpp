#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

int n, a[MAXN];
ll ans, cnt[MAXN], s[MAXN]={LLONG_MAX}, p;

void solve(){
    p=0;
    for (int i=1;i<=n;++i){
        while (s[p]<a[i]){
            ans+=cnt[p];
            p--;
        }
        if (a[i]==s[p]) ans+=cnt[p], cnt[p]++;
        else s[++p]=a[i], cnt[p]=1;
        if (p>1) ans++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    solve();
    cout << ans << '\n';
}