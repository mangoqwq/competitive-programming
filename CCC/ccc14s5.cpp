#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

struct Coord{int x,y;} arr[MAXN];
struct Edge{
    int a,b,d;
    bool operator<(const Edge &x) const{
        return d<x.d;
    }
};
vector<Edge> edges;

int Dist(Coord a, Coord b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
int curr[MAXN], last[MAXN], dist[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){ cin >> arr[i].x >> arr[i].y; }
    for (int i=0;i<=n;++i){
        for (int k=i+1;k<=n;++k){
            edges.push_back({i,k,Dist(arr[i],arr[k])});
        }
    }
    sort(edges.begin(),edges.end());
    for (int i=0,a,b,d;i<edges.size();++i){
        a=edges[i].a, b=edges[i].b, d=edges[i].d;
        if (d>dist[a]) dist[a]=d, last[a]=curr[a];
        if (d>dist[b]) dist[b]=d, last[b]=curr[b];
        curr[a]=max(curr[a],last[b]+1);
        if (a!=0) curr[b]=max(curr[b],last[a]+1);
    }
    cout << curr[0] << '\n';
}
