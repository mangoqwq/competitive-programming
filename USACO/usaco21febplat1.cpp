#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1, L=18, SZ=500;

int n, q;
int a[MAXN], st[MAXN][L], lg2[MAXN], ans[MAXN];
int nxt[MAXN], lst[MAXN], tmp[MAXN];
struct Query{
    int l, r, id;
    bool operator<(const Query &x){
        if (l/SZ==x.l/SZ){
            if ((l/SZ)%2) return r<x.r;
            else return r>x.r;
        }
        else return l<x.l;
    }
}; vector<Query> qs;
stack<int> s;

void build(){
    lg2[1]=0;
    for (int i=2;i<=n;++i) lg2[i]=lg2[i/2]+1;
    for (int i=1;i<=n;++i) st[i][0]=a[i];
    for (int sz=1;sz<L;++sz){
        for (int i=1;i+(1<<sz)-1<=n;++i){
            st[i][sz]=min(st[i][sz-1],st[i+(1<<(sz-1))][sz-1]);
        }
    }
    fill(tmp+1,tmp+1+n,0);
    for (int i=1;i<=n;++i) lst[i]=tmp[a[i]], tmp[a[i]]=i;
    fill(tmp+1,tmp+1+n,n+1);
    for (int i=n;i>=1;--i) nxt[i]=tmp[a[i]], tmp[a[i]]=i;
}

int rmq(int l, int r){
    int sz=lg2[r-l+1];
    return min(st[l][sz],st[r-(1<<sz)+1][sz]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    build();
    for (int i=1;i<=q;++i){
        int l, r; cin >> l >> r;
        qs.push_back({l,r,i});
    }
    sort(qs.begin(),qs.end());
    int pl=1, pr=0, p, curr=0;
    for (auto [l,r,id]:qs){
        while (pr<r){
            pr++;
            p=lst[pr];
            if (p<pl) curr++;
            else if (rmq(p,pr)<a[p]) curr++;
        }
        while (pr>r){
            p=lst[pr];
            if (p<pl) curr--;
            else if (rmq(p,pr)<a[p]) curr--;
            pr--;
        }
        while (pl>l){
            pl--;
            p=nxt[pl];
            if (p>pr) curr++;
            else if (rmq(pl,p)<a[p]) curr++;
        }
        while (pl<l){
            p=nxt[pl];
            if (p>pr) curr--;
            else if (rmq(pl,p)<a[p]) curr--;
            pl++;
        }
        ans[id]=curr;
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}