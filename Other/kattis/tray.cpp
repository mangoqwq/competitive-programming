#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=25;

bool bad[MAXN][3];
ll dp[MAXN][2][2][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=k;++i){
        double dx, dy; cin >> dx >> dy;
        int x=(int)dx, y=(int)dy; x++;
        bad[x][y]=1;
    }
    dp[0][1][1][1]=1;
    for (int i=1;i<=n;++i){
        for (int a=0;a<=3;++a){
            for (int b=0;b<=3;++b){
                for (int c=0;c<=3;++c){
                    if (((a==2)+(b==2)+(c==2))%2||(a==2&&c==2)) continue;
                    if (bad[i][0]&&a!=1) continue;
                    if (bad[i][1]&&b!=1) continue;
                    if (bad[i][2]&&c!=1) continue;
                    dp[i][a!=0][b!=0][c!=0]+=dp[i-1][a!=3][b!=3][c!=3];
                }
            }
        }
    }
    cout << dp[n][1][1][1] << '\n';
}