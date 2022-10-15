#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e3+1;

int a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    int best=0, ans=0;
    for (int j=1;j<=n;++j){
        for (int i=1;i<=n;++i) b[i]=a[i]^a[j];
        sort(b+1,b+1+n);
        int curr=0;
        for (int i=1;i<=n;++i){
            if (b[i]>curr) break;
            if (b[i]==curr) curr++;
        }
        if (curr>best) ans=a[j], best=curr;
        else if (curr==best) ans=min(ans,a[j]);
    }
    cout << best << " " << ans << '\n';
}