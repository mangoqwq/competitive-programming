#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

struct Coord{
    ll x,y;
    ll dist(Coord a){
        return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
    }
} arr[MAXN];
ll dist[MAXN],best[MAXN],c[MAXN],to[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i].x >> arr[i].y >> c[i] >> to[i];
    }
    for (int i=n-1;i>=0;--i){
        dist[i]=arr[i].dist(arr[to[i]])+c[to[i]]+dist[to[i]];
    }
    best[n]=0;
    for (int i=n-1;i>=1;--i){
        best[i]=min(dist[i],arr[i].dist(arr[n])+c[n]);
        for (int j=to[i];j<n;j=to[j]){
            best[i]=min(best[i],arr[i].dist(arr[j])+c[j]+best[j]);
        }
    }
    for (int i=1;i<=n;++i){
        cout << best[i] << '\n';
    }
}