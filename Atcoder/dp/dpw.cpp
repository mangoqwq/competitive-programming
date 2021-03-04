#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+5;

struct Seg{
    ll a[2*MAXN], lz[2*MAXN];
    void push(int v, int l, int r){
        a[v]+=lz[v];
        if (l!=r){
            int mid=l+r>>1;
            lz[v+1]+=lz[v];
            lz[v+2*(mid-l+1)]+=lz[v];
        }
        lz[v]=0;
    }
    void upd(int ql, int qr, ll val, int v, int l, int r){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr) return lz[v]+=val, void(push(v,l,r));
        int mid=l+r>>1;
        upd(ql,qr,val,v+1,l,mid), upd(ql,qr,val,v+2*(mid-l+1),mid+1,r);
        a[v]=max(a[v+1],a[v+2*(mid-l+1)]);
    }
    ll qry(int ql, int qr, int v, int l, int r){
        push(v,l,r);
        if (l>qr||r<ql) return LLONG_MIN;
        if (l>=ql&&r<=qr) return a[v];
        int mid=l+r>>1;
        return max(qry(ql,qr,v+1,l,mid),qry(ql,qr,v+2*(mid-l+1),mid+1,r));
    }
} st;

ll dp[MAXN];
vector<pair<int,int>> in[MAXN], out[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int l, r, w; cin >> l >> r >> w;
        in[l].push_back({l,w});
        out[r].push_back({l,w});
    }
    for (int i=1;i<=n;++i){
        for (auto [x,w]:in[i]) st.upd(0,x-1,w,1,0,n);
        dp[i]=st.qry(0,i-1,1,0,n);
        st.upd(i,i,dp[i],1,0,n);
        for (auto [x,w]:out[i]) st.upd(0,x-1,-w,1,0,n);
    }
    cout << *max_element(dp,dp+1+n) << '\n';
}