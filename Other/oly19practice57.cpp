#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, uwu=1e6;

struct Query{
    int l, r, idx;
    bool operator<(Query b){ return l>b.l; }
}; vector<Query> qs;
int arr[MAXN], st[2*MAXN], lz[2*MAXN], pl, pr, seen[2*uwu+1], n, q, ans[MAXN];

void push(int v, int l, int r){
    if (!lz[v]) return;
    st[v]+=lz[v];
    if (l!=r){
        lz[v+1]+=lz[v];
        lz[v+2*((l+r>>1)-l+1)]+=lz[v];
    }
    lz[v]=0;
}

int rmq(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (ql>r||qr<l) return 0;
    if (l>=ql&&r<=qr) return st[v];
    int mid=l+r>>1;
    return max(rmq(ql,qr,v+1,l,mid),rmq(ql,qr,v+2*(mid-l+1),mid+1,r));
}

void upd(int ql, int qr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (ql>r||qr<l) return;
    if (l>=ql&&r<=qr){ lz[v]++, push(v,l,r); return; }
    int mid=l+r>>1;
    upd(ql,qr,v+1,l,mid); upd(ql,qr,v+2*(mid-l+1),mid+1,r);
    st[v]=max(st[v+1],st[v+2*(mid-l+1)]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a,b;i<=q;++i) cin >> a >> b, qs.push_back({a,b,i});
    sort(qs.begin(),qs.end());
    pl=n+1, pr=n;
    for (Query x:qs){
        while (pl>x.l){
            if (seen[arr[--pl]+uwu]) pr=min(pr,seen[arr[pl]+uwu]-1);
            seen[arr[pl]+uwu]=pl;
            upd(pl,pr);
        }
        ans[x.idx]=rmq(x.l,x.r);
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}