#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int a, b, c; cin >> a >> b >> c;
        ll x, y, g=1;
        for (int i=1;i<c;++i) g=g*10;
        x=y=g;
        while (to_string(x).size()<a) x=x*2;
        while (to_string(y).size()<b) y=y*3;
        cout << x << " " << y << '\n';
    }
}