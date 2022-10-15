#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, L=27;

int bit[MAXN][L], a[MAXN];
ll p2[L];

void upd(int x, int i, int val){
    for (;i<MAXN;i+=i&-i) bit[i][x]+=val;
}

int get(int x, int i){
    int ret=0;
    for (;i>0;i-=i&-i) ret+=bit[i][x];
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    p2[0]=1;
    for (int i=1;i<=26;++i) p2[i]=p2[i-1]*2;
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        for (int j=0;j<=26;++j) if (p2[j]&a[i]) upd(j,i,1);
    }
    for (int i=1,op,l,r;i<=q;++i){
        ll ans=0, c1, c0;
        cin >> op >> l >> r;
        if (op==1){
            for (int j=0;j<=26;++j) upd(j,l,(1&(r>>j))-(1&(a[l]>>j)));
            a[l]=r;
            continue;
        }
        for (int j=0;j<=26;++j){
            c1=get(j,r)-get(j,l-1), c0=r-l+1-c1;
            if (op==2) ans+=p2[j]*(c1*(r-l)-(c1*(c1-1)/2));
            if (op==3) ans+=p2[j]*(c1*(c1-1)/2);
            if (op==4) ans+=p2[j]*(c1*c0);
        }
        cout << ans << '\n';
    }
}