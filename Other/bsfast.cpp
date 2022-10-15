#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n, q, lastans, tmp, st[MAXN*2];
void upd(int idx, int val, int v=1, int l=1, int r=n){
    if (l==r) return void(st[v]=val);
    if (idx<=mid) upd(idx,val,lc,l,mid);
    else upd(idx,val,rc,mid+1,r);
    st[v]=min(st[lc],st[rc]);
}
int qry(int ql, int qr, int k, int v=1, int l=1, int r=n){
    if (l>qr||r<ql||st[v]>=k) return 0;
    if (l==r) return l;
    if (tmp=qry(ql,qr,k,lc,l,mid)) return tmp;
    else return qry(ql,qr,k,rc,mid+1,r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> tmp, upd(i,tmp);
    for (int i=1;i<=q;++i){
        int op; cin >> op;
        if (op==1){
            int p, x; cin >> p >> x;
            p^=lastans, x^=lastans;
            upd(p,x);
        }
        else{
            int l, r, k; cin >> l >> r >> k;
            l^=lastans, r^=lastans, k^=lastans;
            cout << (lastans=qry(l,r,k)) << '\n';
        }
    }
}