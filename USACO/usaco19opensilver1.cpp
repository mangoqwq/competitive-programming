#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

bool g[MAXN][MAXN];
bool fr[MAXN], fc[MAXN];

int cnt(int x1, int y1, int x2, int y2){
    int ret=0;
    for (int i=x1;i<=x2;++i)
        for (int j=y1;j<=y2;++j)
            ret+=g[i][j];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            char a; cin >> a;
            g[i][j]=a=='R';
            g[i][j]=g[i][j]^fr[i]^fc[j];
            if (i==1&&g[i][j]) fc[j]^=1, g[i][j]^=1;
            if (j==1&&g[i][j]) fr[i]^=1, g[i][j]^=1;
        }
    }
    int tmp=cnt(2,2,n,n);
    if (tmp==(n-1)*(n-1)) cout << "1 1" << '\n';
    else if (tmp==n-1){
        for (int j=2;j<=n;++j) if (cnt(2,j,n,j)==n-1) return cout << 1 << " " << j << '\n', 0;
        for (int i=2;i<=n;++i) if (cnt(i,2,i,n)==n-1) return cout << i << " " << 1 << '\n', 0;
        cout << -1 << '\n';
    }
    else if (tmp==1){
        for (int i=2;i<=n;++i)
            for (int j=2;j<=n;++j)
                if (g[i][j]) return cout << i << " " << j << '\n', 0;
    }
    else cout << -1 << '\n';
}