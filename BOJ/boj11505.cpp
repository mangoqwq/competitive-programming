#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n, m, k, arr[MAXN];
struct Seg{
    ll st[4*MAXN];
    void upd(int i, int x, int v=1, int l=1, int r=n){
        if (l==r) st[v]=x;
        else{
            int mid=l+r>>1;
            if (i<=mid) upd(i,x,v*2,l,mid);
            else upd(i,x,v*2+1,mid+1,r);
            st[v]=st[v*2]*st[v*2+1]%mod;
        }
    }
    ll qry(int ql, int qr, int v=1, int l=1, int r=n){
        if (ql>r||qr<l) return 1;
        if (l>=ql&&r<=qr) return st[v];
        int mid=l+r>>1;
        return qry(ql,qr,v*2,l,mid)*qry(ql,qr,v*2+1,mid+1,r)%mod;
    }
} st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    fill(st.st+1,st.st+1+4*n,1);
    for (int i=1;i<=n;++i) cin >> arr[i], st.upd(i,arr[i]);
    for (int i=1;i<=m+k;++i){
        int op; cin >> op;
        if (op==1){
            int idx, val; cin >> idx >> val;
            st.upd(idx,val);
        }
        if (op==2){
            int l, r; cin >> l >> r;
            cout << st.qry(l,r) << '\n';
        }
    }
}