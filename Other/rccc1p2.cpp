#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1501;

ll a[MAXN], ans;
unordered_map<ll,ll> freq, cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], freq[a[i]]++;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (j==i) continue;
            cnt[a[i]*a[j]]++;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (j==i) continue;
            ll tmp=a[i]*a[j];
            if (a[i]==a[j]) ans+=cnt[tmp]-2*(freq[a[i]]+freq[a[j]]-3);
            else ans+=cnt[tmp]-2*(freq[a[i]]+freq[a[j]]-1);
        }
    }
    cout << ans << '\n';
}