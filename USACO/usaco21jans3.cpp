#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int a[MAXN][2], b[MAXN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) for (int j=1, x;j<=n;++j) cin >> x, a[j][i%2]+=x, b[i][j%2]+=x;
    for (int i=1;i<=n;++i) a[0][0]+=max(a[i][0],a[i][1]), b[0][0]+=max(b[i][0],b[i][1]);
    cout << max(a[0][0],b[0][0]) << '\n';
}