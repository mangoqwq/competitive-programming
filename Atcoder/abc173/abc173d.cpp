#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN], tot;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    for (int i=1;i<n;++i) tot+=arr[n-i/2];
    cout << tot << '\n'; 
}