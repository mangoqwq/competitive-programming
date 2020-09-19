#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, cnt=0, last=0; cin >> n;
        for (ll i=1;;i*=2){
            ll curr=last*2+i*i;
            if (curr>n) break;
            last=curr;
            n-=curr, cnt++;
        }
        cout << cnt << '\n';
    }
}