#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        vector<ll> a(3);
        for (ll &x:a) cin >> x;
        sort(a.begin(),a.end());
        if (a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) cout << "R" << '\n';
        else if (a[0]*a[0]+a[1]*a[1]>a[2]*a[2]) cout << "A" << '\n';
        else cout << "O" << '\n';
    }
}