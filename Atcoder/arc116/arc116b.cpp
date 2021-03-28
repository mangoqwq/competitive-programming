#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=2e5+1;

ll a[MAXN], ans, curr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        ans+=a[i]*a[i];
        ans%=mod;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;++i){
        ans+=curr*a[i]; ans%=mod;
        curr*=2; curr%=mod;
        curr+=a[i]; curr%=mod;
    }
    cout << ans << '\n';
}