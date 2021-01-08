#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e3+1;

int x[MAXN], y[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> x[i] >> y[i];
    int ans=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (abs(y[j]-y[i])<=abs(x[j]-x[i])) ans++;
        }
    }
    cout << ans << '\n';
}