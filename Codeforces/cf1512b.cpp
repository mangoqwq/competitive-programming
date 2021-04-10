#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=401;

struct Point{ int x, y; };
char grid[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        Point a={0,0}, b;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                cin >> grid[i][j];
                if (grid[i][j]=='.') continue;
                if (a.x==0) a={i,j};
                else b={i,j};
            }
        }
        if (a.x==b.x) a.x=(a.x==n?1:a.x+1);
        else if (a.y==b.y) a.y=(a.y==n?1:a.y+1);
        grid[a.x][a.y]='*';
        grid[b.x][b.y]='*';
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                if (i==a.x&&j==b.y) grid[i][j]='*';
                if (i==b.x&&j==a.y) grid[i][j]='*';
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
}