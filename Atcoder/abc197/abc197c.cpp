#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=21;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int ans=2*inf;
    for (int i=0;i<(1<<(n-1));++i){
        int curr=0, val=0;
        for (int j=1;j<=n;++j){
            val|=arr[j];
            if (1&(i>>(j-1))) curr^=val, val=0;
        }
        curr^=val;
        ans=min(ans,curr);
    }
    cout << ans << '\n';
}