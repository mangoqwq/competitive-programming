#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int p[MAXN], val[MAXN], sz[MAXN];

int Find(int v){ return (p[v]==v?v:p[v]=Find(p[v])); }
void Union(int a, int b){
    a=Find(a); b=Find(b);
    if (a==b) return;
    if (sz[b]>sz[a]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    val[a]=max(val[a],val[b]);
}
struct Edge{
    int val, a, b;
    bool operator<(const Edge &x) const{ return val<x.val; }
} e[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> val[i], p[i]=i, sz[i]=1;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        e[i]={max(val[a],val[b]),a,b};
    }
    sort(e+1,e+n);
    ll ans=0;
    for (int i=1;i<=n-1;++i){
        ans+=val[Find(e[i].a)]+val[Find(e[i].b)];
        Union(e[i].a,e[i].b);
    }
    cout << ans << '\n';
}