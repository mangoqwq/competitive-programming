#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int p[MAXN], sz[MAXN];
char r[MAXN];

int Find(int a){ return p[a]==a?a:p[a]=Find(p[a]); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a^b){
        if (sz[b]>sz[a]) swap(a,b);
        p[b]=a, sz[a]+=sz[b];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    iota(p+1,p+1+n,1);
    fill(sz+1,sz+1+n,1);
    for (int i=1;i<=n;++i) cin >> r[i];
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        if (r[a]==r[b]) Union(a,b);
    }
    int ans=0;
    while (q--){
        int a, b; cin >> a >> b;
        ans+=Find(a)==Find(b);
    }
    cout << ans << '\n';
}