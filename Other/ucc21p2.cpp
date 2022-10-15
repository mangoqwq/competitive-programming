#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int curr=0, ans=0;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        if (a%2==0) curr+=a;
        else curr=0;
        ans=max(ans,curr);
    }
    cout << ans << '\n';
}