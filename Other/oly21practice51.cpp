#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN];
ll pre[101][101], cnt[101], suf[101];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) suf[a[i]]++;
    ll ans=0;
    for (int i=1;i<=n;++i){
        suf[a[i]]--;
        for (int j=1;j<=100;++j) ans+=pre[j][a[i]]*suf[j];
        for (int j=1;j<=100;++j) pre[j][a[i]]+=cnt[j];
        cnt[a[i]]++;
    }
    cout << ans << '\n';
}