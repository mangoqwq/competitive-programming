#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll tot=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                tot+=gcd(i,gcd(j,k));
    cout << tot << '\n';
}