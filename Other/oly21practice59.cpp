#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        if (a[i]<a[i-1]+1) ans+=a[i-1]+1-a[i], a[i]=a[i-1]+1;
    }
    cout << ans << '\n';
}