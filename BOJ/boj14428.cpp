#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define lc v+1
#define rc v+2*(mid-l+1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, a[MAXN];
pair<int,int> st[2*MAXN];

void upd(int i, int x, int v=1, int l=1, int r=n){
    if (l==r) return void(st[v]={x,i});
    int mid=l+r>>1;
    i<=mid?upd(i,x,lc,l,mid):upd(i,x,rc,mid+1,r);
    st[v]=min(st[lc],st[rc]);
}

pair<int,int> qry(int ql, int qr, int v=1, int l=1, int r=n){
    if (l>qr||r<ql) return {inf,0};
    if (l>=ql&&r<=qr) return st[v];
    int mid=l+r>>1;
    return min(qry(ql,qr,lc,l,mid),qry(ql,qr,rc,mid+1,r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        upd(i,a[i]);
    }
    int q; cin >> q;
    while (q--){
        int op; cin >> op;
        if (op==1){
            int i, v; cin >> i >> v;
            upd(i,v);
        }
        if (op==2){
            int l, r; cin >> l >> r;
            cout << qry(l,r).second << '\n';
        }
    }
}