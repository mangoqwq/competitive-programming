#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

string s;
int n, q, temp[10];
struct nd{
    int cnt[10], lz, l, r, mid;
    void inc(){
        for (int i=0;i<=9;++i) temp[i]=cnt[i];
        for (int i=0;i<=9;++i) cnt[i]=temp[(i-lz+1000000)%10];
    }
    int a(){ return 2*(mid-l+1); }
    int tot(){
        int ret=0;
        for (int i=0;i<=9;++i) ret+=cnt[i]*i;
        return ret;
    }
    void push(int v);
} st[2*MAXN];

void nd::push(int v){
    inc();
    if (l!=r){
        st[v+1].lz+=lz;
        st[v+a()].lz+=lz;
    }
    lz=0;
}

void build(int v=1, int l=1, int r=n){
    int mid=(l+r>>1);
    st[v].l=l, st[v].r=r, st[v].mid=mid;
    if (l==r) st[v].cnt[s[l]-'0']++;
    else{
        build(v+1,l,mid);
        build(v+st[v].a(),mid+1,r);
        for (int i=0;i<=9;++i) st[v].cnt[i]=st[v+1].cnt[i]+st[v+st[v].a()].cnt[i];
    }
}

void upd(int l, int r, int v=1){
    st[v].push(v);
    if (st[v].r<l||st[v].l>r) return;
    if (st[v].l>=l&&st[v].r<=r){ st[v].lz++, st[v].push(v); return; }
    upd(l,r,v+1), upd(l,r,v+st[v].a());
    for (int i=0;i<=9;++i) st[v].cnt[i]=st[v+1].cnt[i]+st[v+st[v].a()].cnt[i];  
}

int qry(int l, int r, int v=1){
    st[v].push(v);
    if (st[v].r<l||st[v].l>r) return 0;
    if (st[v].l>=l&&st[v].r<=r) return st[v].tot();
    return qry(l,r,v+1)+qry(l,r,v+st[v].a());
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    cin >> s; s=" "+s;
    build();
    while (q--){
        int l, r; cin >> l >> r;
        cout << qry(l,r) << '\n';
        upd(l,r);
    }
}