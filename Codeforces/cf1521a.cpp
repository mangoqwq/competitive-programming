#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a, b; cin >> a >> b;
        if (b==1) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            cout << a*(b-1) << " " << a*(b+1) << " " << 2*a*b << '\n';
        }
    }
}