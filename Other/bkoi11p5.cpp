#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=200;

int n, m;
struct Edge{
    int a, b, v1, v2;
    ll calc(int p1, int p2){ return (ll)v1*p1+(ll)v2*p2; };
};
struct Item{
    int v1, v2; ll p1, p2;
    bool operator<(const Item &x) const{ return (ll)v1*v2<(ll)x.v1*x.v2; }
} best;
vector<Edge> edges, ans;
struct UnionFind{
    int n;
    vector<int> p, sz;
    UnionFind(){}
    UnionFind(int _n) : n(_n){
        p.resize(n), sz.resize(n);
        reset();
    }
    void reset(){
        iota(p.begin(),p.end(),0);
        fill(sz.begin(),sz.end(),1);
    }
    int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]); }
    bool Union(int a, int b){
        a=Find(a), b=Find(b);
        if (a==b) return 0;
        if (sz[b]<sz[a]) swap(a,b);
        p[b]=a, sz[a]+=sz[b];
        return sz[a]==n;
    }
} dsu;

struct Point{
    int x, y;
    bool operator==(const Point &a) const{ return x==a.x&&y==a.y; }
    void print(){ cout << '(' << x << ',' << y << ')' << ' '; }
};
Point calc(ll p1, ll p2, int trace=0){
    sort(edges.begin(),edges.end(),[&](Edge a, Edge b){ return a.calc(p1,p2)<b.calc(p1,p2); });
    dsu.reset();
    int c1=0, c2=0;
    for (Edge e:edges){
        if (dsu.Find(e.a)==dsu.Find(e.b)) continue;
        c1+=e.v1, c2+=e.v2;
        if (trace) ans.push_back(e);
        if (dsu.Union(e.a,e.b)) break;
    }
    return {c1,c2};
}
void solve(Point p1, Point p2){
    ll f1=p1.y-p2.y, f2=p2.x-p1.x;
    Point p3=calc(f1,f2);
    if (p3.x<=p1.x||p3.x>=p2.x) return;
    best=min(best,{p3.x,p3.y,f1,f2});
    solve(p1,p3), solve(p3,p2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dsu=UnionFind(n);
    edges.resize(m);
    for (auto &[a,b,v1,v2]:edges) cin >> a >> b >> v1 >> v2;
    Point p1=calc(1,0), p2=calc(0,1);
    best=min((Item){p1.x,p1.y,1,0},(Item){p2.x,p2.y,0,1});
    // p1.print(); p2.print();
    // cout << '\n';
    solve(p1,p2);
    calc(best.p1,best.p2,1);
    cout << best.v1 << " " << best.v2 << '\n';
    for (auto [a,b,v1,v2]:ans) cout << a << " " << b << '\n';
}