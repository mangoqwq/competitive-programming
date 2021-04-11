#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+5;

int n, a[MAXN], nxt[MAXN], pos[MAXN], cnt[MAXN], uniq;
struct Seg{
    ll in[2*MAXN], out[2*MAXN], cnt[2*MAXN], lz[2*MAXN];
    void push(int v, int l, int r){
        in[v]+=cnt[v]*lz[v];
        out[v]+=((r-l+1)-cnt[v])*lz[v];
        if (l!=r){
            lz[lc]+=lz[v];
            lz[rc]+=lz[v];
        }
        lz[v]=0;
    }
    void pull(int v, int l, int r){
        push(lc,l,mid), push(rc,mid+1,r);
        in[v]=in[lc]+in[rc];
        out[v]=out[lc]+out[rc];
        cnt[v]=cnt[lc]+cnt[rc];
    }
    void upd(int ql, int qr, int val, int v=1, int l=1, int r=n+1){
        push(v,l,r);
        if (ql>qr||l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ lz[v]+=val; push(v,l,r); return; }
        upd(ql,qr,val,lc,l,mid), upd(ql,qr,val,rc,mid+1,r);
        pull(v,l,r);
    }
    void enable(int i, int v=1, int l=1, int r=n+1){
        push(v,l,r);
        if (l==r){ cnt[v]=1, swap(in[v],out[v]); return; }
        if (i<=mid) enable(i,lc,l,mid);
        else enable(i,rc,mid+1,r);
        pull(v,l,r);
    }
    ll qry(int ql, int qr, int v=1, int l=1, int r=n+1){
        push(v,l,r);
        if (l>qr||r<ql) return 0;
        if (l>=ql&&r<=qr) return in[v];
        return qry(ql,qr,lc,l,mid)+qry(ql,qr,rc,mid+1,r);
    }
} st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) pos[i]=n+1;
    for (int i=n;i>=1;--i){
        nxt[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;++i){
        st.upd(i,i,uniq);
        if (cnt[a[i]]==0) uniq++;
        if (cnt[a[i]]==1) uniq--;
        cnt[a[i]]++;
        if (cnt[a[i]]==1) st.enable(i);
    }
    ll ans=0;
    for (int i=1;i<=n-1;++i){
        int j=nxt[i];
        st.upd(i+1,j,-1);
        st.upd(j+1,nxt[j],1);
        ans+=st.qry(i+1,nxt[i]-1);
        if (nxt[i]!=n+1) st.enable(nxt[i]);
    }
    cout << ans << '\n';
}