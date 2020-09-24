#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=150'001;

int bit[MAXN*2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int tot=0; ll ans=0;
    for (int i=n+1;i<2*n;i+=i&-i) bit[i]++;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        if (a==2) a=-1;
        tot+=a;
        for (int i=tot+n;i>0;i-=i&-i) ans+=bit[i];
        for (int i=tot+n+1;i<2*n;i+=i&-i) bit[i]++;
    }
    cout << ans << '\n';
}