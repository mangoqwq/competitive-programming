#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+1, MAXM=5e5+1;

int n, m, arr[MAXN], b[MAXN], d[MAXM];
struct nd{
    int l, r, v, lz; 
} st[4*MAXN];

void push(int v){
    if (!st[v].lz) return;
    st[v].v+=st[v].lz;
    if (st[v].l!=st[v].r){
        st[2*v].lz+=st[v].lz;
        st[2*v+1].lz+=st[v].lz;
    }
    st[v].lz=0;
}

int build(int v=1, int l=1, int r=n){
    st[v].l=l, st[v].r=r; st[v].lz=0;
    if (l==r){
        st[v].v=arr[l];
        return st[v].v;
    }
    int mid=l+r>>1;
    return st[v].v=max(build(2*v,l,mid),build(2*v+1,mid+1,r));
}

void upd(int l, int r=n, int val=-1, int v=1){
    push(v);
    if (st[v].r<l||st[v].l>r) return;
    if (st[v].l>=l&&st[v].r<=r) st[v].lz+=val, push(v);
    else upd(l,r,val,2*v), upd(l,r,val,2*v+1), st[v].v=max(st[v*2].v,st[v*2+1].v);
}

int get(int l=1, int r=n, int v=1){
    push(v);
    if (st[v].r<l||st[v].l>r) return -1;
    if (st[v].l>=l&&st[v].r<=r) return st[v].v;
    return max(get(l,r,v*2),get(l,r,v*2+1));
}

void res(){
    for (int i=1;i<=n;++i) upd(i,i,i);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> b[i], arr[i]=i;
    sort(b+1,b+1+n); build();
    int ans=0;
    for (int i=1;i<=m;++i){
        cin >> d[i];
        upd(upper_bound(b+1,b+1+n,d[i])-b);
        if (!get()){
            ans++; res();
        }
        cout << ans << " ";
    }
}