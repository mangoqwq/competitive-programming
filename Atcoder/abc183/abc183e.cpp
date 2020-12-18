#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2001;

ll arr[MAXN][MAXN][3], val[MAXN][MAXN];
int dx[]={0,-1,-1}, dy[]={-1,-1,0};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    arr[1][1][0]=arr[1][1][1]=arr[1][1][2]=1;
    int h, w; cin >> h >> w;
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            char a; cin >> a;
            if (a=='#') continue;
            for (int x=0;x<=2;++x) val[i][j]+=arr[i+dx[x]][j+dy[x]][x], val[i][j]%=mod;
            for (int x=0;x<=2;++x) arr[i][j][x]+=arr[i+dx[x]][j+dy[x]][x]+val[i][j], arr[i][j][x]%=mod;
        }
    }
    cout << val[h][w] << '\n';
}