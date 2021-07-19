#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+10;

int a[MAXN];
ll cnt[MAXN][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, b, c; cin >> n >> b >> c;
    c=min(c,b);
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i){
        cnt[i][0]=a[i];
        int r=min(cnt[i][0],cnt[i-1][0]);
        cnt[i][0]-=r, cnt[i-1][0]-=r; cnt[i][1]+=r;
        r=min(cnt[i][0],cnt[i-1][1]);
        cnt[i][0]-=r, cnt[i-1][1]-=r; cnt[i][2]+=r;
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<=2;++j){
            ans+=cnt[i][j]*(b+c*j);
        }
    }
    cout << ans << '\n';
}
