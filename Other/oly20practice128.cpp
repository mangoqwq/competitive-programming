#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, t, m; cin >> n >> t >> m;
    for (int i=1;i<=m;++i){
        int a; cin >> a;
        cnt[a]++;
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        if (m-cnt[i]<t) ans++;
    }
    cout << ans << '\n';
}