#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], arr[i]+=arr[i-1];
    int ans=0x3f3f3f3f;
    for (int i=1;i<=n;++i) ans=min(ans,abs(2*arr[i]-arr[n]));
    cout << ans << '\n'; 
}