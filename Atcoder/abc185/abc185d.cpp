#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+4;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i) cin >> arr[i];
    sort(arr+1,arr+1+m);
    arr[++m]=n+1;
    int k=n, ans=0;
    for (int i=1;i<=m;++i) if (arr[i]-arr[i-1]-1!=0) k=min(k,arr[i]-arr[i-1]-1);
    for (int i=1;i<=m;++i) ans+=(arr[i]-arr[i-1]+k-2)/k;
    cout << ans << '\n';
}