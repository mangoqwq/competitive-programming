#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

struct Query{
    int l, r, x, id;
    bool operator<(const Query &a) const{ return r<a.r; }
} qs[MAXN];
int seen[MAXN], a[MAXN];
bool ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=q;++i){
        cin >> qs[i].l >> qs[i].r >> qs[i].x;
        qs[i].id=i;
    }
    sort(qs+1,qs+1+q);
    int p=0;
    for (int i=1;i<=q;++i){
        auto [l,r,x,id]=qs[i];
        while (p<r) ++p, seen[a[p]]=p;
        for (int j=1;j*j<x;++j){
            if (x%j==0&&seen[j]>=l&&seen[x/j]>=l) ans[id]=1;
        }
    }
    for (int i=1;i<=q;++i) cout << (ans[i]?"YES":"NO") << '\n';
}