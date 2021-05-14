#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    int ans=0;
    for (int i=1;i<=1000;++i){
        bool yes=1;
        for (int j=1;j<=n;++j) yes&=i>=a[j]&&i<=b[j];
        ans+=yes;
    }
    cout << ans << '\n';
}