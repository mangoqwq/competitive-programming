#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int arr1[MAXN], arr2[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr1[i];
    copy(arr1,arr1+1+n,arr2);
    sort(arr2+1,arr2+1+n);
    int cnt=0;
    for (int i=1;i<=n;++i) cnt+=arr1[i]!=arr2[i];
    cout << (cnt<=2?"YES":"NO") << '\n';
}