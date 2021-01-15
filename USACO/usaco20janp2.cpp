#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+5, MAXQ=2e5+1;

int a[MAXN]; ll ans[MAXQ];
ll cl[MAXN][21], cr[MAXN][21];
struct Query{ int l, r, id; };

void solve(int l, int r, vector<Query> qs){
    int mid=l+r>>1;
    vector<Query> ql, qr, q;
    for (Query x:qs){
        if (x.r<mid) ql.push_back(x);
        else if (x.l>mid) qr.push_back(x);
        else q.push_back(x);
    }
    for (int k=0;k<=20;++k){
        ms(cl[mid+1],0), ms(cr[mid],0);
        if (k==0) cl[mid+1][0]=1;
        for (int i=mid;i>=l;--i){
            for (int j=0;j<=20;++j) cl[i][j]=cl[i+1][j];
            if (a[i]==k) cl[i][a[i]]++;
            for (int j=a[i];j<=20;++j) cl[i][a[i]]+=cl[i+1][j], cl[i][a[i]]%=mod;
        }
        for (int i=mid+1;i<=r;++i){
            for (int j=0;j<=20;++j) cr[i][j]=cr[i-1][j];
            if (a[i]<k) continue;
            cr[i][a[i]]++;
            for (int j=a[i];j>=0;--j) cr[i][a[i]]+=cr[i-1][j], cr[i][a[i]]%=mod;
        }
        for (int i=l;i<=r;++i){
            cl[i][0]=accumulate(cl[i],cl[i]+21,0LL)%mod;
            cr[i][0]=accumulate(cr[i],cr[i]+21,0LL)%mod;
        }
        for (Query x:q){
            ans[x.id]+=1LL*cl[x.l][0]*(cr[x.r][0]+1);
            ans[x.id]%=mod;
        }
    }
    if (!ql.empty()) solve(l,mid-1,ql);
    if (!qr.empty()) solve(mid+1,r,qr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i];
    cin >> q;
    vector<Query> qs(q);
    for (int i=0;i<q;++i){
        cin >> qs[i].l >> qs[i].r;
        qs[i].id=i;
    }
    solve(1,n,qs);
    for (int i=0;i<q;++i) cout << ans[i] << '\n';
}