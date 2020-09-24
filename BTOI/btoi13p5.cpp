#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=4005;

char a[MAXN][MAXN];
int dist[MAXN][MAXN];
struct Item{
    int x, y, d;
    bool operator<(const Item &a) const{
        return d>a.d;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r, c; cin >> r >> c;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> a[i][j];
        }
    }
    deque<Item> q; ms(dist,0x3f);
    q.push_back({1,1,1}); dist[1][1]=1;
    while (!q.empty()){
        int x=q.front().x, y=q.front().y, d=q.front().d; q.pop_front();
        for (int i=-1;i<=1;++i){
            for (int j=-1;j<=1;++j){
                if (abs(i)+abs(j)!=1) continue;
                if (a[x+i][y+j]==0 || a[x+i][y+j]=='.') continue;
                if (d+(a[x][y]!=a[x+i][y+j])<dist[x+i][y+j]){
                    dist[x+i][y+j]=d+(a[x][y]!=a[x+i][y+j]);
                    if (a[x][y]!=a[x+i][y+j]) q.push_back({x+i,y+j,d+1});
                    else q.push_front({x+i,y+j,d});
                }
            }
        }
    }
    int ans=0;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            if (a[i][j]!='.') ans=max(ans,dist[i][j]);
        }
    }
    cout << ans << '\n';
    

}