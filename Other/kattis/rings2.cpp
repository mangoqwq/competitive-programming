#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=105;

bool g[MAXN][MAXN];
int v[MAXN][MAXN], mx;

void print(int i){
    if (mx<10){
        if (i==0) cout << "..";
        else cout << "." << i;
    }
    else{
        if (i==0) cout << "...";
        else if (i<10) cout << ".." << i;
        else cout << "." << i;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char a; cin >> a;
            g[i][j]=a=='T';
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!g[i][j]) continue;
            v[i][j]=100;
            for (int x=0;x<=n+1;++x){
                for (int y=0;y<=m+1;++y){
                    if (g[x][y]) continue;
                    v[i][j]=min(v[i][j],abs(x-i)+abs(y-j));
                }
            }
            mx=max(mx,v[i][j]);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            print(v[i][j]);
        }
        cout << '\n';
    }
}