#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int lg2[MAXN], deg[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    lg2[1]=0;
    for (int i=2;i<=n;++i){
        int a, b; cin >> a >> b;
        deg[a]++, deg[b]++;
        lg2[i]=lg2[i/2]+1;
    }
    deg[1]++;
    int ans=n-1;
    for (int i=1;i<=n;++i) ans+=lg2[deg[i]]+((deg[i]&deg[i]-1)?1:0);
    cout << ans << '\n';
}