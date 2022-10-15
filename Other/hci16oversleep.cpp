#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

char a[MAXN][MAXN];
struct Coord{
    int x, y;
} s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin >> a[i][j];
            if (a[i][j]=='s') s={i,j};
        }
    }
    queue<Coord> q; q.push(s); int cnt=0;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=1;i<=qsize;++i){
            int x=q.front().x, y=q.front().y; q.pop();
            if (a[x][y]=='e'){ cout << cnt-1 << '\n'; return 0; }
            if (a[x][y]=='X'||x<1||y<1||x>n||y>m) continue;
            a[x][y]='X';
            q.push({x+1,y});
            q.push({x-1,y});
            q.push({x,y+1});
            q.push({x,y-1});
        } cnt++;
    }
    cout << -1 << '\n';
}