#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int idx[MAXN], a[MAXN], vis[MAXN];
int ans[MAXN], p;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], idx[a[i]]=i;
    for (int i=1;i<=n;++i){
        for (int j=idx[i]-1;j>=i;--j){
            if (vis[j]) return cout << -1 << '\n', 0;
            vis[j]=1;
            ans[++p]=j;
            idx[a[j]]=j+1;
            idx[a[j+1]]=j;
            swap(a[j],a[j+1]);
        }
    }
    if (p!=n-1) return cout << -1 << '\n', 0;
    for (int i=1;i<=n-1;++i) cout << ans[i] << '\n';
}