#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e4+1;

int a[MAXN], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; n++;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=2;i<=n;++i){
        int b; cin >> b;
        ans+=(a[i]+a[i-1])*b;
    }
    if (ans%2==0) cout << ans/2 << '\n';
    else cout << ans/2 << ".5" << '\n';
}