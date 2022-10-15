#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+6;

struct fenwick{
    int arr[MAXN];
    void ins(int i){ for (;i<MAXN;i+=i&-i) arr[i]++; }
    int qry(int i){
        int ret=0;
        for (;i>0;i-=i&-i) ret+=arr[i];
        return ret;
    }
    int qry(int l, int r){
        return qry(r)-qry(l-1); 
    }
} bit;
struct nd{ int mn, lz; } st[MAXN*2];
int n, q;

void push(int v, int l, int r){
    st[v].mn+=st[v].lz;
    if (l!=r){
        int mid=l+r>>1;
        st[v+1].lz+=st[v].lz;
        st[v+2*(mid-l+1)].lz+=st[v].lz;
    }
    st[v].lz=0;
}

void upd(int ql, int qr, int val=-1, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (ql>r||qr<l) return;
    if (l>=ql&&r<=qr) return st[v].lz+=val, push(v,l,r), void();
    int mid=l+r>>1;
    upd(ql,qr,val,v+1,l,mid), upd(ql,qr,val,v+2*(mid-l+1),mid+1,r);
    st[v].mn=min(st[v+1].mn,st[v+2*(mid-l+1)].mn);
}

void fix(int v=1, int l=1, int r=n){
    push(v,l,r);
    if (st[v].mn>0) return;
    if (l==r){
        bit.ins(l);
        st[v].lz+=l, push(v,l,r);
        return;
    }
    int mid=l+r>>1;
    fix(v+1,l,mid), fix(v+2*(mid-l+1),mid+1,r);
    st[v].mn=min(st[v+1].mn,st[v+2*(mid-l+1)].mn);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q; n=min(n,MAXN-1);
    for (int i=1;i<=n;++i) upd(i,i,i);
    while (q--){
        int op, l, r; cin >> op >> l >> r;
        l=min(n,l), r=min(n,r);
        if (op==1){
            upd(l,r), fix();
        }
        else{
            cout << bit.qry(l,r) << '\n';
        }
    }
}