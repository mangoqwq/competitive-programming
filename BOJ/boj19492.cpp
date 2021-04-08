#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

int n, m;
ll a[MAXN];

struct Seg{
    ll mx[2*MAXN], tot[2*MAXN], acc[2*MAXN], paint[2*MAXN], inc[2*MAXN];
    ll build(int v=1, int l=1, int r=n){
        if (l==r) return acc[v]=a[l];
        return acc[v]=build(lc,l,mid)+build(rc,mid+1,r);
    }
    void push(int v=1, int l=1, int r=n){
        if (paint[v]!=-1){
            mx[v]=paint[v];
            tot[v]=(r-l+1)*paint[v];
            if (l!=r){
                paint[lc]=paint[v], inc[lc]=0;
                paint[rc]=paint[v], inc[rc]=0;
            }
            paint[v]=-1;
        }
        if (inc[v]!=0){
            mx[v]+=inc[v]*a[r];
            tot[v]+=inc[v]*acc[v];
            if (l!=r){
                inc[lc]+=inc[v];
                inc[rc]+=inc[v];
            }
            inc[v]=0;
        }
    }
    int find(ll val, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l==r) return l;
        push(lc,l,mid);
        if (mx[lc]>val) return find(val,lc,l,mid);
        else return find(val,rc,mid+1,r);
    }
    void upd(ll val, int ql, int qr=n, int v=1, int l=1, int r=n){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ paint[v]=val, push(v,l,r); return; }
        upd(val,ql,qr,lc,l,mid), upd(val,ql,qr,rc,mid+1,r);
        tot[v]=tot[lc]+tot[rc], mx[v]=max(mx[lc],mx[rc]);
    }
} st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(st.paint,-1);
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n); st.build();
    ll last=0;
    for (int i=1;i<=m;++i){
        ll d, b; cin >> d >> b;
        st.inc[1]+=d-last; last=d; st.push();
        ll old=st.tot[1];
        if (st.mx[1]>b) st.upd(b,st.find(b));
        cout << old-st.tot[1] << '\n';
    }
}