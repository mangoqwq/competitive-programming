#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<ll>> cnt(n+1,vector<ll>(n+1));
    cnt[0][0]=1;
    ll tot=0, curr;
    for (int i=1;i<=n;++i){
        ll a; cin >> a; tot+=a;
        curr=0;
        for (int j=n;j>=1;--j){
            cnt[j][tot%(j+1)]+=cnt[j-1][tot%j];
            cnt[j][tot%(j+1)]%=mod;
            curr+=cnt[j-1][tot%j];
            curr%=mod;
        }
    }
    cout << curr << '\n';
}