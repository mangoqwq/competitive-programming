#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN], cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i) cin >> a[i] >> b[i];
    int k; cin >> k;
    for (int i=1;i<=k;++i) cin >> c[i] >> d[i];
    int ans=0, curr;
    for (int i=0;i<(1<<k);++i){
        ms(cnt,0); curr=0;
        for (int j=1;j<=k;++j){
            if (1&(i>>(j-1))) cnt[c[j]]++;
            else cnt[d[j]]++;
        }
        for (int j=1;j<=m;++j){
            if (cnt[a[j]]&&cnt[b[j]]) curr++;
        }
        ans=max(ans,curr);
    }
    cout << ans << '\n';
}