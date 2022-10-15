#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll ans=0, curr=1;
    while (to_string(curr).size()<to_string(n).size()){
        ans+=9*curr;
        curr*=100;
    }
    if (curr<=n) ans+=n-curr;
    string str=to_string(n);
    if (str.size()%2) ans++;
    cout << ans << '\n';

}