#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, d, dep[MAXN], p[MAXN], in[MAXN], out[MAXN], T, ans;
vector<int> c[MAXN];
vector<pair<int,int>> arr={{0,0}};
struct Seg{
    int st[4*MAXN], lz[4*MAXN];
    void push(int v, int l, int r){
        st[v]=min(st[v],lz[v]);
        if (l!=r){
            lz[lc]=min(lz[lc],lz[v]);
            lz[rc]=min(lz[rc],lz[v]);
        }
        lz[v]=inf;
    }
    void upd(int ql, int qr, int val, int v=1, int l=1, int r=2*n){
        push(v,l,r);
        if (ql>r||qr<l) return;
        if (l>=ql&&r<=qr){ lz[v]=val, push(v,l,r); return; }
        upd(ql,qr,val,lc,l,mid), upd(ql,qr,val,rc,mid+1,r);
        st[v]=min(st[lc],st[rc]);
    }
    int qry(int idx, int v=1, int l=1, int r=2*n){
        push(v,l,r);
        if (l==r) return st[v];
        if (idx<=mid) return qry(idx,lc,l,mid);
        else return qry(idx,rc,mid+1,r);
    }
} st;

void dfs(int v){
    in[v]=++T;
    for (int to:c[v]) dfs(to);
    out[v]=++T;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d; d--;
    for (int i=1;i<n;++i){
        cin >> p[i];
        c[p[i]].push_back(i);
        dep[i]=dep[p[i]]+1;
        arr.push_back({dep[i],i});
    }
    ms(st.st,0x3f), ms(st.lz,0x3f);
    dfs(0);
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    for (auto [vdep,v]:arr){
        if (vdep+st.qry(in[v])<=d) continue;
        ans++;
        for (int i=0;i<=d;++i,v=p[v]){
            st.upd(in[v],out[v],vdep-2*dep[v]);
        }
    }
    cout << ans << '\n';
}