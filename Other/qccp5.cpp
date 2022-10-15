#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;
const double pi=3.14159265358979323846;

struct Vector{
    double x, y, z;
    void get(){ cin >> x >> y >> z; }
    double abs(){ return sqrt(dot(*this)); }
    double dot(Vector a){ return x*a.x+y*a.y+z*a.z; }
    double ang(Vector a){
        return acos(dot(a)/abs()/a.abs());
    }
    double dist(Vector a){
        return ang(a)*abs();
    }
} vecs[MAXN];
struct Edge{
    int to; double w;
    bool operator<(const Edge &x) const{ return w>x.w; }
};
priority_queue<Edge> pq;
vector<Edge> adj[MAXN];
vector<int> airport;
double in[MAXN], out[MAXN]; 
int val[MAXN];

void work(double dist[]){
    while (!pq.empty()){
        auto [v,d]=pq.top(); pq.pop();
        for (auto [to,w]:adj[v]){
            if (d+w<dist[to]){
                dist[to]=d+w;
                pq.push({to,dist[to]});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r, t, k; cin >> n >> m >> r >> t >> k;
    airport.resize(k);
    for (int &x:airport) cin >> x;
    for (int i=1;i<=n;++i) cin >> val[i], vecs[i].get();
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        double c=vecs[a].dist(vecs[b]);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=1;i<=n;++i) in[i]=out[i]=1e18;
    for (int x:airport) out[x]=0, pq.push({x,0});
    work(out);
    in[1]=0, pq.push({1,0});
    work(in);
    int ans=-1;
    for (int i=1;i<=n;++i) if (in[i]+out[i]<t) ans=max(ans,val[i]);
    cout << ans << '\n';
}