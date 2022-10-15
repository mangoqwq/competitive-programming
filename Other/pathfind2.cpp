#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+1, inf=0x3f3f3f3f;

set<int> bl[MAXN];
struct Segment{
    int l, r, id;
    bool operator<(const Segment &x) const{
        return r<x.r;
    }
}; vector<Segment> s[MAXN];
struct Disjoint{
    int p[2*MAXN];
    void init(){
        for (int i=1;i<2*MAXN;++i) p[i]=i;
    }
    int Find(int a){ return p[a]==a?a:p[a]=Find(p[a]); }
    void Union(int a, int b){
        a=Find(a), b=Find(b);
        if (a==b) return;
        p[b]=a;
    }
} dsu;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    dsu.init();
    int n, m, k, q, T=0; cin >> n >> m >> k >> q;
    for (int i=1;i<=n;++i) bl[i].insert(m+1);
    for (int i=1;i<=k;++i){
        int r, c; cin >> r >> c;
        bl[r].insert(c);
    }
    for (int i=1;i<=n;++i){
        int last=0;
        for (int x:bl[i]){
            if (x!=last+1){
                s[i].push_back({last+1,x-1,++T});
            }
            last=x;
        }
    }
    for (int i=2;i<=n;++i){
        int p=0; s[i-1].push_back({inf,inf});
        for (Segment x:s[i]){
            while (x.l>s[i-1][p].r) p++;
            while (x.r>=s[i-1][p].r) dsu.Union(x.id,s[i-1][p++].id);
            if (x.r>=s[i-1][p].l) dsu.Union(x.id,s[i-1][p].id);
        }
    }
    while (q--){
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        int a=lower_bound(s[sr].begin(),s[sr].end(),Segment{sc,sc,0})->id;
        int b=lower_bound(s[er].begin(),s[er].end(),Segment{ec,ec,0})->id;
        cout << (dsu.Find(a)==dsu.Find(b)?"YES":"NO") << '\n';
    }
}