#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5, MAXK=55;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct Item{
    ll dist, x, b; 
};
ll dist[MAXN][MAXK], b[MAXN];
bool mat[MAXK][MAXK];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        cin >> b[i];
    }
    for (int i=1;i<=k;++i){
        for (int j=1;j<=k;++j){
            char a; cin >> a;
            mat[i][j]=a=='1';
        }
    }
    for (int i=1;i<=k;++i) mat[0][i]=mat[b[n]][i], mat[i][0]=mat[i][b[n]];
    b[n]=0;
    ms(dist,0x3f);
    deque<Item> q;
    q.push_front({0,1,b[1]});
    dist[1][b[1]]=0;
    while (!q.empty()){
        Item v=q.front(); q.pop_front();
        if (v.x!=1&&dist[v.x-1][v.b]==inf){
            dist[v.x-1][v.b]=v.dist+1;
            q.push_back({v.dist+1,v.x-1,v.b});
        }
        if (v.x!=n&&dist[v.x+1][v.b]==inf){
            dist[v.x+1][v.b]=v.dist+1;
            q.push_back({v.dist+1,v.x+1,v.b});
        }
        if (mat[v.b][b[v.x]]&&dist[v.x][b[v.x]]==inf){
            dist[v.x][b[v.x]]=v.dist;
            q.push_front({v.dist,v.x,b[v.x]});
        }
    }
    cout << (dist[n][0]==inf?-1:dist[n][0]) << '\n';
}