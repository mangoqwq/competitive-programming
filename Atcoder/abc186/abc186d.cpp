#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    ll diff=0, ans=0;
    for (int i=2;i<=n;++i) diff+=arr[i]-arr[1];
    for (int i=1;i<=n;++i){
        ans+=diff;
        diff-=(n-i)*(arr[i+1]-arr[i]);
    }
    cout << ans << '\n';
}