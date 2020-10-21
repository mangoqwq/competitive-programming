#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

double dist[MAXN][MAXN][2*MAXN], cost[MAXN][MAXN];
struct Item{ int x, y, f; };
queue<Item> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m, f, k; cin >> n >> m >> f >> k;
        f=min(f,200);
        for (int i=1;i<=100;++i){
            for (int j=1;j<=100;++j){
                cost[i][j]=-1;
                for (int k=0;k<=200;++k) dist[i][j][k]=1e9;
            }
        }
        for (int i=1,a,b;i<=k;++i){
            cin >> a >> b;
            double badquestion;
            cin >> badquestion;
            if (cost[a][b]<0) cost[a][b]=badquestion;
            cost[a][b]=min(cost[a][b],badquestion);
        }
        q.push({1,1,f}); dist[1][1][f]=0;
        while (!q.empty()){
            int x, y, ff; x=q.front().x, y=q.front().y, ff=q.front().f; q.pop();
            for (int i=-1;i<=1;++i){
                for (int j=-1;j<=1;++j){
                    if (abs(i)+abs(j)!=1) continue;
                    if (x+i<1||x+i>100||y+j<1||y+j>100) continue;
                    if (ff==0) continue;
                    if (dist[x][y][ff]<dist[x+i][y+j][ff-1]){
                        dist[x+i][y+j][ff-1]=dist[x][y][ff];
                        q.push({x+i,y+j,ff-1});
                    }
                }
            }
            if (cost[x][y]>=0){
                for (int i=1;i+ff<=f;++i){
                    if (dist[x][y][ff]+cost[x][y]*i<dist[x][y][ff+i]){
                        dist[x][y][ff+i]=dist[x][y][ff]+cost[x][y]*i;
                        q.push({x,y,ff+i});
                    }
                }
            }
        }
        double best=1e8+1;
        for (int i=0;i<=f;++i) best=min(best,dist[n][m][i]);
        if (best>1e8) printf("Stranded on the shoulder\n");
        else printf("%.2f\n",best);

    }
}