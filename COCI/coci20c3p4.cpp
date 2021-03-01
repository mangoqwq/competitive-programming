#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define pc(x) (__builtin_popcount(x))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

bool g[MAXN][10];
int dp[MAXN][1<<10];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) for (int j=0;j<m;++j){
        char a; cin >> a;
        g[i][j]=a=='#';
    }
    ms(dp,0x3f);
    dp[0][0]=0;
    for (int r=1;r<=n;++r){
        for (int i=0;i<(1<<m);++i){
            bool flag=1;
            for (int j=0;j<m;++j) if (!g[r][j]&&(1&(i>>j))) flag=0;
            if (!flag) continue;
            int cnt=0; flag=0;
            for (int j=0;j<m;++j){
                if (!g[r][j]||(1&(i>>j))) flag=0; 
                else if (!flag) cnt++, flag=1;
            }
            for (int j=0;j<(1<<m);++j){
                dp[r][i]=min(dp[r][i],dp[r-1][j]+cnt+pc(i)-pc(i&j));
            }
        }
    }
    cout << *min_element(dp[n],dp[n]+(1<<m)) << '\n';
}