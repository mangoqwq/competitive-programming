#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll dist[101][101][101];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; ms(dist,0x3f);
    for (int i=1;i<=n;++i){
        for (int j=1,a;j<=n;++j){
            cin >> a;
            if (a!=0) dist[1][i][j]=a;
            if (i==j) dist[1][i][j]=0;
        }
    }
    for (int k=1;k<=n;++k){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                dist[1][i][j]=min({dist[1][i][j],dist[1][i][k]+dist[1][k][j]});
            }
        }
    }
    for (int d=2;d<=n;++d){
        for (int k=1;k<=n;++k){
            for (int i=1;i<=n;++i){
                for (int j=1;j<=n;++j){
                    dist[d][i][j]=min({dist[d][i][j],max(dist[d-1][i][k],dist[1][k][j])});
                }
            }
        }
    }
    int q; cin >> q;
    for (int i=1,a,b,d;i<=q;++i){
        cin >> a >> b >> d;
        cout << (dist[d][a][b]==inf?0:dist[d][a][b]) << '\n';
    }
}