#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+5;

ll up[MAXN], down[MAXN], arr[MAXN], mx[MAXN], mn[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    mx[0]=mn[n+1]=-0x3f3f3f3f;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        mx[i]=max(mx[i-1],arr[i]);
    }
    for (int i=n;i>=1;--i) mn[i]=max(mn[i+1],arr[i]);
    for (int i=2;i<=n;++i){
        up[i]=up[i-1]+mx[i]-arr[i];
        down[i]=min(up[i-1],down[i-1])+mn[i]-arr[i];
    }
    cout << min(up[n],down[n]) << '\n';
}