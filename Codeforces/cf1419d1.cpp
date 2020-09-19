#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    cout << (n-1)/2 << '\n';
    int pl=1, pr=n;
    for (int i=1;i<=n;++i){
        if (i%2==1) cout << arr[pr--] << " ";
        else cout << arr[pl++] << " ";
    }
}