#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=351;

bool vis[MAXN][MAXN][MAXN];
int cnt[MAXN]; int ans=350;

void rem(int r, int c, int sz){
    if (!vis[r][c][sz]) return;
    vis[r][c][sz]=0, cnt[sz]--;
    rem(r,c,sz+1);
    rem(r+1,c,sz+1);
    rem(r,c+1,sz+1);
    rem(r+1,c+1,sz+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int q; cin >> q;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            for (int k=min(i,j);k>=1;--k)
                vis[i][j][k]=1, cnt[k]++;
    cnt[0]=1;
    while (q--){
        int a, b; cin >> a >> b;
        rem(a,b,1);
        while (!cnt[ans]) ans--;
        cout << ans << '\n';
    }
}