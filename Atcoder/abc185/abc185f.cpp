#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

int bit[MAXN];

void upd(int i, int x){ for (;i<MAXN;i+=i&-i) bit[i]^=x; }
int qry(int i){
    int ret=0;
    for (;i>0;i-=i&-i) ret^=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        upd(i,a);
    }
    while (q--){
        int t, x, y; cin >> t >> x >> y;
        if (t==1) upd(x,y);
        if (t==2) cout << (qry(y)^qry(x-1)) << '\n';
    }
}