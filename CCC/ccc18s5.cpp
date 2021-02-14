#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct DSU{
    int par[MAXN];
    int Find(int x){ return (par[x]==x?x:par[x]=Find(par[x])); }
    void Union(int a, int b){
        a=Find(a), b=Find(b);
        if (a==b) return;
        par[b]=a;
    }
} row, col;
struct Edge{
    int a, b, c, r;
    bool operator<(const Edge &other) const{ return c<other.c; }
} arr[2*MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, p, q; cin >> n >> m >> p >> q;
    ll ans=0;
    for (int i=1;i<=p;++i){
        int a, b, c; cin >> a >> b >> c;
        arr[i]={a,b,c,0}; ans+=1LL*c*n;
    }
    for (int i=1;i<=q;++i){
        int a, b, c; cin >> a >> b >> c;
        arr[p+i]={a,b,c,1}; ans+=1LL*c*m;
    }
    sort(arr+1,arr+1+p+q);
    iota(col.par,col.par+1+n,0);
    iota(row.par,row.par+1+m,0);
    for (int i=1;i<=p+q;++i){
        auto [a,b,c,r] = arr[i];
        if (!r&&row.Find(a)!=row.Find(b))
            row.Union(a,b), ans-=1LL*c*n, m--;
        if (r&&col.Find(a)!=col.Find(b))
            col.Union(a,b), ans-=1LL*c*m, n--;
    }
    cout << ans << '\n';
}