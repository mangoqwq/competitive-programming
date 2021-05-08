#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, T;
struct Item{
    ll tot, pre, suf;
    Item operator+(const Item &x){
        return {tot+x.tot,max(pre,tot+x.pre),max(x.suf,x.tot+suf)};
    }
};
struct Node{ int lc, rc; Item x; } st[MAXN*40];
int a[MAXN];
void build(int v=0, int l=1, int r=n){
    if (l==r) st[v]={-1,-1,{a[l],a[l],a[l]}};
    else{
        st[v].lc=++T, st[v].rc=++T;
        build(st[v].lc,l,mid), build(st[v].rc,mid+1,r);
        st[v].x=st[st[v].lc].x+st[st[v].rc].x;
    }
}
int upd(int i, int x, int v, int l=1, int r=n){
    st[++T]=st[v]; v=T;
    if (l==r) st[v]={-1,-1,{x,x,x}};
    else{
        if (i<=mid) st[v].lc=upd(i,x,st[v].lc,l,mid);
        else st[v].rc=upd(i,x,st[v].rc,mid+1,r);
        st[v].x=st[st[v].lc].x+st[st[v].rc].x;
    }
    return v;
}
Item qry(int ql, int qr, int v, int l=1, int r=n){
    if (l>qr||r<ql) return {0,-inf,-inf};
    if (l>=ql&&r<=qr) return st[v].x;
    return qry(ql,qr,st[v].lc,l,mid)+qry(ql,qr,st[v].rc,mid+1,r);
}
vector<int> rts;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    build();
    rts.push_back(0);
    int q; cin >> q;
    while (q--){
        char op; cin >> op;
        if (op=='U'){
            int i, x; cin >> i >> x;
            rts.push_back(upd(i,x,rts.back()));
        }
        else if (op=='G'){
            int i; cin >> i;
            rts.push_back(rts[i]);
        }
        else{
            int l, r; cin >> l >> r;
            Item ans=qry(l,r,rts.back());
            cout << (op=='P'?ans.pre:ans.suf) << '\n';
        }
    }
}