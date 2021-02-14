#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1005;

struct Coord{ int x, y; };
int grid[MAXN][MAXN], cnt, ans;
int mnx[MAXN*MAXN], mny[MAXN*MAXN], mxx[MAXN*MAXN], mxy[MAXN*MAXN];
bool can[MAXN*MAXN];
int arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ms(mnx,0x3f), ms(mny,0x3f);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            int a; cin >> a; grid[i][j]=a;
            if (a&&mnx[a]==inf) cnt++;
            mnx[a]=min(mnx[a],i);
            mxx[a]=max(mxx[a],i);
            mny[a]=min(mny[a],j);
            mxy[a]=max(mxy[a],j);
        }
    }
    for (int i=1;i<=n*n;++i){
        if (mnx[i]==inf) continue;
        arr[mnx[i]][mny[i]]++;
        arr[mnx[i]][mxy[i]+1]--;
        arr[mxx[i]+1][mny[i]]--;
        arr[mxx[i]+1][mxy[i]+1]++;
    }
    ms(can,1);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            can[grid[i][j]]&=arr[i][j]==1;
        }
    }
    for (int i=1;i<=n*n;++i) ans+=can[i];
    if (cnt==1) cout << n*n-1 << '\n';
    else cout << ans << '\n';
}