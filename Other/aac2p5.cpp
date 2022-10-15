#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n, q, lg2[MAXN], arr[MAXN], seen[MAXN];
struct Sparse{
    int a[MAXN], st[MAXN][20];
    int typ;
    void build(){
        lg2[1]=0;
        for (int i=2;i<=n;++i) lg2[i]=lg2[i/2]+1;
        for (int i=1;i<=n;++i) st[i][0]=a[i];
        for (int sz=1;sz<=19;++sz){
            for (int i=1;i+(1<<sz)-1<=n;++i){
                if (typ==0) st[i][sz]=min(st[i][sz-1],st[i+(1<<(sz-1))][sz-1]);
                if (typ==1) st[i][sz]=max(st[i][sz-1],st[i+(1<<(sz-1))][sz-1]);
            }
        }
    }
    int qry(int l, int r){
        int sz=lg2[r-l+1];
        if (typ==0) return min(st[l][sz],st[r-(1<<sz)+1][sz]);
        else return max(st[l][sz],st[r-(1<<sz)+1][sz]);
    }
} nxt, dp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    nxt.typ=0, dp.typ=1;
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        dp.a[i]=min(dp.a[i-1]+1,i-seen[arr[i]]);
        seen[arr[i]]=i;
    }
    fill(seen+1,seen+1+n,n+1);
    for (int i=n;i>=1;--i){
        nxt.a[i]=seen[arr[i]];
        seen[arr[i]]=i;
    }
    nxt.build(); dp.build();
    int ans=0;
    while (q--){
        int l, r; cin >> l >> r;
        l^=ans, r^=ans;
        int lo=r, hi=nxt.qry(l,r)-1;
        hi=min(hi,nxt.qry(lo,hi)-1);
        cout << (ans=dp.qry(lo,hi)) << '\n';
    }
}