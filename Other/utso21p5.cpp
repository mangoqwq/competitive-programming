#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

struct nd{
    ll tot, s, cnt;
} st[8*MAXN];
int n, q;
ll ans[MAXN];

void push(int t, int l, int r){
    st[t].tot+=st[t].s*st[t].cnt;
    if (l!=r){
        st[t*2].cnt+=st[t].cnt;
        st[t*2+1].cnt+=st[t].cnt;
    }
    st[t].cnt=0;
}

void upd(int ql, int qr, ll v, int t=1, int l=1, int r=n){
    push(t,l,r);
    if (l>qr||r<ql) return;
    if (l>=ql&&r<=qr) st[t].s+=v;
    else{
        int mid=l+r>>1;
        upd(ql,qr,v,t*2,l,mid);
        upd(ql,qr,v,t*2+1,mid+1,r);
    }
}

void pay(int ql, int qr, int t=1, int l=1, int r=n){
    push(t,l,r);
    if (l>qr||r<ql) return;
    if (l>=ql&&r<=qr) st[t].cnt++;
    else{
        int mid=l+r>>1;
        pay(ql,qr,t*2,l,mid);
        pay(ql,qr,t*2+1,mid+1,r);
    }
}

void collect(int t=1, int l=1, int r=n){
    push(t,l,r);
    if (l==r) ans[l]=st[t].tot;
    else{
        int mid=l+r>>1;
        st[t*2].tot+=st[t].tot;
        st[t*2+1].tot+=st[t].tot;
        collect(t*2,l,mid);
        collect(t*2+1,mid+1,r);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        upd(i,i,x);
    }
    for (int i=1;i<=q;++i){
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op==1){
            cin >> x;
            upd(l,r,x);
        }
        if (op==2){
            pay(l,r);
        }
    collect();
    for (int i=1;i<=n;++i) cout << ans[i] << " ";
    cout << '\n';
    }
}