#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    int curr, last; cin >> last; ans+=last;
    for (int i=2;i<n;++i){
        cin >> curr;
        ans+=min(curr,last);
        swap(curr,last);
    }
    ans+=last;
    cout << ans << '\n';

}