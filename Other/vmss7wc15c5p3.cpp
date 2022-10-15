#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2005;

ll bit[MAXN][MAXN];

void Update(int a, int idx, ll val){
    for (int i=idx;i<MAXN;i+=i&-i) bit[a][i]+=val;
}

ll Query(int a, int idx){
    ll tot=0;
    for (int i=idx;i>0;i-=i&-i) tot+=bit[a][i];
    return tot;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for (int i=1,cmd,r,c,x;i<=n;++i){
        cin >> cmd >> r >> c >> x;
        if (cmd==1) Update(r+c,r,x);
        if (cmd==2) ans+=Query(r+c,r)-Query(r+c,r-x-1);
    }
    cout << ans%mod << '\n';
}