#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, w; cin >> n >> w;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    int p=n; ll ans=0;
    for (int i=1;i<=n;++i){
        while (arr[p]+arr[i]>w) p--;
        ans+=p;
    } 
    for (int i=1;i<=n;++i) ans-=arr[i]+arr[i]<=w;
    cout << ans/2 << '\n';
}