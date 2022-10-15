#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int st[MAXN][18], arr[MAXN];

void build(int sz){
    for (int i=1;i<=sz;++i) st[i][0]=arr[i];
    for (int i=1;i<=17;++i){
        for (int l=1,r=l+(1<<i)-1;r<=sz;++l,++r){
            st[l][i]=max(st[l][i-1],st[l+(1<<i-1)][i-1]);
        }
    }
}

int rmq(int l, int r){
    int i=31-__builtin_clz(r-l+1);
    return max(st[l][i], st[r-(1<<i)+1][i]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    build(n);
    while (q--){
        int l, r; cin >> l >> r;
        cout << rmq(l,r) << '\n';
    }
}