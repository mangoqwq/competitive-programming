#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        if (k) k--, ans[i]=ans[i-1];
        else ans[i]=ans[i-1]^1;
    }
    if (ans[n]!=ans[0]) cout << -1 << '\n';
    else{
        for (int i=1;i<=n;++i) cout << ans[i] << (i!=n?' ':'\n');
    }
}