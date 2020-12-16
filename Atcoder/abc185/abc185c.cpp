#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

bool vis[12];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll l, ans=1; cin >> l;
    for (int i=l-1;i>=l-11;--i){
        ans*=i;
        for (int j=1;j<=11;++j){
            if (vis[j]) continue;
            if (ans%j==0) vis[j]=1, ans/=j;
        }
    }
    cout << (ll)ans << '\n';
}