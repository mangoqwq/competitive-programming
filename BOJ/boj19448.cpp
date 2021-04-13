#include <bits/stdc++.h>

using namespace std;

int best[29][29]; // 1 cells, 2 cells

void precompute(){
    for (int i=6;i>=0;--i){
        for (int j=i;j>=0;--j){
            for (int x=28;x>=0;--x){
                for (int y=28;y>=0;--y){
                    if (x>=1) best[x][y]=max(best[x][y],best[x-1][y]+i);
                    if (y>=1) best[x][y]=max(best[x][y],best[x][y-1]+i+j);
                }
            }
        }
    }
}

int g[57][7];
int dp[57][(1<<7)][29];

void solve(int n, int m){
    memset(g,0,sizeof g); memset(dp,-1,sizeof dp);
    if (m>n){
        for (int j=0;j<n;++j){
            for (int i=1;i<=m;++i){
                char a; cin >> a;
                if (a=='B') g[i][j]=-1;
                if (a=='G') g[i][j]=1;
            }
        }
        swap(n,m);
    }
    else{
        for (int i=1;i<=n;++i){
            for (int j=0;j<m;++j){
                char a; cin >> a;
                if (a=='B') g[i][j]=-1;
                if (a=='G') g[i][j]=1;
            }
        }
    }
    // for (int i=1;i<=n;++i){
    //     for (int j=0;j<m;++j){
    //         cout << g[i][j];
    //     }
    //     cout << '\n';
    // }
    dp[0][(1<<m)-1][0]=0;
    int mx=1;
    for (int i=1;i<=m;++i) mx=mx*3;
    for (int r=1;r<=n;++r){
        for (int mask=0;mask<=mx;++mask){
            int ones=0, twos=0; // number of 1s added
            int last=-1, msk=mask, nxt=0, lst=0;
            bool valid=1;
            for (int i=0;i<m;++i){
                int b=msk%3; msk/=3;
                if (g[r][i]==-1&&b!=0) valid=0;
                if (b==0){
                    if (g[r][i]==-1) nxt+=(1<<i);
                    lst+=(1<<i);
                }
                if (b==1){
                    if (last==-1){
                        last=i;
                    }
                    else{
                        if (last!=i-1) valid=0;
                        else{
                            int tot=g[r][i]+g[r][i-1];
                            if (tot==1) ones++;
                            else if (tot==2) twos++;
                            last=-1;
                        }
                    }
                    nxt+=(1<<i);
                    lst+=(1<<i);
                } 
                if (b==2){
                    int tot=g[r][i]+g[r-1][i];
                    if (tot==1) ones++;
                    else if (tot==2) twos++;
                    nxt+=(1<<i);
                }
            }
            if (last!=-1) valid=0;
            if (!valid) continue;
            for (int i=twos;i<=28;++i){
                if (dp[r-1][lst][i-twos]!=-1) dp[r][nxt][i]=max(dp[r][nxt][i],dp[r-1][lst][i-twos]+ones);
            }
        }
    }
    int ans=-1;
    for (int i=0;i<=28;++i){
        if (dp[n][(1<<m)-1][i]!=-1){
            ans=max(ans,best[dp[n][(1<<m)-1][i]][i]);
            // cout << dp[n][(1<<m)-1][i] << " " << i << '\n';
        }
    }
    if (ans==-1) cout << "No solution" << '\n';
    else cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    precompute();
    for (int _=1;;++_){
        int n, m; cin >> n >> m;
        if (n==0&&m==0) break;
        cout << "Case " << _ << ": ";
        solve(n,m);
    }
}