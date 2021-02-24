#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e6+1;

int n, m, q;
bitset<MAXN> r, c;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    while (q--){
        char a; int x; cin >> a >> x;
        a=='R'?r.flip(x):c.flip(x);
    }
    cout << r.count()*m+c.count()*n-2*r.count()*c.count() << '\n';
}