#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    int ans=0;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        if (x==0) ans++;
    }
    for (int i=1;i<=m;++i){
        int x; cin >> x;
        if (x==1) ans--;
    }
    for (int i=1;i<=k;++i){
        int x; cin >> x;
    }
    cout << abs(ans) << '\n';
}
