#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=155;

int n, grid[MAXN][MAXN];
ll pre[MAXN][MAXN][2][2], dp[MAXN][MAXN][2][2];

bool good(int row, int l, int r){ return (grid[row][r]-grid[row][l-1])==(r-l+1); }
void build(){
    for (int i=0;i<=1;++i)
        for (int j=0;j<=1;++j)
            for (int r=1;r<=n;++r)
                for (int c=1;c<=n;++c){
                    pre[r][c][i][j]=pre[r][c][i][j]+
                                    pre[r-1][c][i][j]+
                                    pre[r][c-1][i][j]-
                                    pre[r-1][c-1][i][j];
                    pre[r][c][i][j]=(pre[r][c][i][j]%mod+mod)%mod;
                }
}

ll qry(int l1, int l2, int r1, int r2, int i, int j){
    ll ret=(pre[l2][r2][i][j]-
            pre[l2][r1-1][i][j]-
            pre[l1-1][r2][i][j]+
            pre[l1-1][r1-1][i][j])%mod;
    return (ret%mod+mod)%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j){
        char a; cin >> a;
        grid[i][j]=a=='G';
        grid[i][j]+=grid[i][j-1];
    }
    ll ans=0;
    for (int row=1;row<=n;++row){
        swap(dp,pre);
        ms(dp,0); build();
        for (int l=1;l<=n;++l) for (int r=l;r<=n;++r){
            if (!good(row,l,r)) continue;
            dp[l][r][0][0]= qry(1,l,r,n,     0,0)+
                            qry(1,l,r+1,n,   0,1)+
                            qry(1,l-1,r,n,   1,0)+
                            qry(1,l-1,r+1,n, 1,1);
            dp[l][r][0][1]= qry(1,l,l,r,     0,1)+
                            qry(1,l-1,l,r,   1,1);
            dp[l][r][1][0]= qry(l,r,r,n,     1,0)+
                            qry(l,r,r+1,n,   1,1);
            dp[l][r][1][1]= qry(l,r,l,r,     1,1)+
                            1;

            for (int i=0;i<=1;++i) for (int j=0;j<=1;++j){
                dp[l][r][i][j]%=mod;
                ans+=dp[l][r][i][j];
                ans%=mod;
            }
        }
    }
    cout << ans << '\n';
}