#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

map<int,int> m[2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q; cin >> n >> q;
    m[0][n]=n-2, m[1][n]=n-2;
    ll tot=(n-2)*(n-2);
    while (q--){
        int op, x; cin >> op >> x; op--;
        auto it=m[op].lower_bound(x);
        if (it==m[op].begin()) m[op^1].begin()->second=x-2;
        tot-=it->second;
        m[op][x]=it->second;
    }
    cout << tot << '\n';
}