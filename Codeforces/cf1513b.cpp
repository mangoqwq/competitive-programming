#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int a[MAXN];
ll fact[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    fact[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> a[i];
        int mn=a[1], cnt=0, val=a[1];
        for (int i=1;i<=n;++i){
            if (a[i]<mn) mn=a[i], cnt=1;
            else if (a[i]==mn) cnt++;
            val&=a[i];
        }
        if (cnt<2||val!=mn) cout << 0 << '\n';
        else{
            ll tmp=((ll)cnt)*(cnt-1)%mod;
            cout << fact[n-2]*tmp%mod << '\n';
        }
    }
}