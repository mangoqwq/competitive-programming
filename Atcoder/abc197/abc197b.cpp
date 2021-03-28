#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

bool grid[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(grid,0);
    int n, m, x, y; cin >> n >> m >> x >> y;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char a; cin >> a;
            if (a=='.') grid[i][j]=1;
        }
    }
    int ans=1;
    for (int i=y-1;;--i){
        if (!grid[x][i]) break;
        else ans++;
    }
    for (int i=y+1;;++i){
        if (!grid[x][i]) break;
        else ans++;
    }
    for (int i=x-1;;--i){
        if (!grid[i][y]) break;
        else ans++;
    }
    for (int i=x+1;;++i){
        if (!grid[i][y]) break;
        else ans++;
    }
    cout << ans << '\n';
}