#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2001;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s; cin >> n >> m >> s;
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char a; cin >> a;
            if (a=='.') continue;
            int x1=max(i,s), y1=max(j,s), x2=min(i+s-1,n), y2=min(j+s-1,m);
            ans+=(x2-x1+1)*(y2-y1+1);
        }
    }
    cout << setprecision(14) << (0.0+ans)/(n-s+1)/(m-s+1) << '\n';
}