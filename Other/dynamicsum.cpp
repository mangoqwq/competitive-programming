#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

int N, Q, T;
struct Node{ int lc, rc; ll x; } st[MN*40];
void build(int v=0, int l=1, int r=N){
    if (l==r) st[v]={-1,-1,0};
    else{
        st[v].lc=++T, st[v].rc=++T;
        build(st[v].lc,l,mid), build(st[v].rc,mid+1,r);
        st[v].x=st[st[v].lc].x+st[st[v].rc].x;
    }
}
int upd(int i, ll x, int v, int l=1, int r=N){
    st[++T]=st[v]; v=T;
    if (l==r) st[v]={-1,-1,st[v].x+x};
    else{
        if (i<=mid) st[v].lc=upd(i,x,st[v].lc,l,mid);
        else st[v].rc=upd(i,x,st[v].rc,mid+1,r);
        st[v].x=st[st[v].lc].x+st[st[v].rc].x;
    }
    return v;
}
ll qry(int ql, int qr, int v, int l=1, int r=N){
    if (l>qr||r<ql) return 0;
    if (l>=ql&&r<=qr) return st[v].x;
    return qry(ql,qr,st[v].lc,l,mid)+qry(ql,qr,st[v].rc,mid+1,r);
}
vector<int> rts;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    build(); rts.push_back(0);
    ll ans = 0, t = 0;
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            ll i, v; cin >> i >> v;
            i ^= ans, v ^= ans;
            rts.push_back(upd(i, v, rts.back()));
            t++;
        }
        if (op == 2){
            ll l, r, x; cin >> l >> r >> x;
            l ^= ans, r ^= ans, x ^= ans;
            cout << (ans = qry(l, r, rts[t - x])) << '\n';
        }
    }
}
