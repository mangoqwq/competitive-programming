#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+5;

int a[MAXN], pre[MAXN], suf[MAXN];

void solve(){
    int n; cin >> n;
    ms(pre,0); ms(suf,0); ms(a,0);
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=n;i>=2;--i) a[i]=a[i]-a[i-1];
    pre[2]=1, suf[n]=1;
    for (int i=3;i<=n;++i){
        if (a[i]==a[i-1]) pre[i]=pre[i-1]+1;
        else pre[i]=1;
    }
    for (int i=n-1;i>=2;--i){
        if (a[i]==a[i+1]) suf[i]=suf[i+1]+1;
        else suf[i]=1;
    }
    int ans=1;
    for (int i=2;i<n;++i) ans=max(ans,suf[i+1]+1);
    for (int i=3;i<=n;++i) ans=max(ans,pre[i-1]+1);
    for (int i=3;i<=n;++i){
        if ((a[i]+a[i-1])%2==1) continue;
        int curr=2, val=(a[i]+a[i-1])/2;
        if (i!=n&&a[i+1]==val) curr+=suf[i+1];
        if (i!=3&&a[i-2]==val) curr+=pre[i-2];
        ans=max(ans,curr);
    }
    cout << ans+1 << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}