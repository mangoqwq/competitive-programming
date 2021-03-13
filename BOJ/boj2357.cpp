#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1, L=16;

int mn[MAXN][L+1], mx[MAXN][L+1], lg[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        mn[i][0]=mx[i][0]=x;
    }
    lg[1]=0;
    for (int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
    for (int j=1;j<=L;++j){
        for (int i=1;i+(1<<j)-1<=n;++i){
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
        }
    }
    for (int i=1;i<=m;++i){
        int l, r; cin >> l >> r;
        int sz=lg[r-l+1];
        cout << min(mn[l][sz],mn[r-(1<<sz)+1][sz]) << " ";
        cout << max(mx[l][sz],mx[r-(1<<sz)+1][sz]) << '\n';
    }
}