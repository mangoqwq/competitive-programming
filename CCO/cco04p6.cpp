#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x,idx) (1&(x>>idx))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<10);

int dp[MAXN][MAXN][2];
string p1[10],p2[10];

int solve(int mask1, int mask2, int lead){
    int &curr=dp[mask1][mask2][lead]; int best;
    if (curr!=-1) return curr;
    if (lead==0){
        
        for (int i=0;i<10;++i){
            best=10;
            if (!is(mask1,i)) continue;
            bool must=0,lose;
            for (int j=0;j<10;++j){
                if (!is(mask2,j)) continue;
                must|=p1[i][0]==p2[j][0];
            }
            for (int j=0;j<10;++j){
                if (!is(mask2,j)) continue;
                if (must){
                    if (p1[i][0]!=p2[j][0]) continue;
                    lose=(p1[i][1]<p2[j][1]);
                    best=min(best,solve(mask1-(1<<i),mask2-(1<<j),lose)+(!lose));
                }
                else{
                    best=min(best,solve(mask1-(1<<i),mask2-(1<<j),0)+1);
                }
            }
            curr=max(curr,best);
        }
    }
    if (lead==1){
        curr=10;
        for (int i=0;i<10;++i){
            best=0;
            if (!is(mask2,i)) continue;
            bool must=0,lose;
            for (int j=0;j<10;++j){
                if (!is(mask1,j)) continue;
                must|=p2[i][0]==p1[j][0];
            }
            for (int j=0;j<10;++j){
                if (!is(mask1,j)) continue;
                if (must){
                    if (p2[i][0]!=p1[j][0]) continue;
                    lose=(p2[i][1]>p1[j][1]);
                    best=max(best,solve(mask1-(1<<j),mask2-(1<<i),lose)+(!lose));
                }
                else{
                    best=max(best,solve(mask1-(1<<j),mask2-(1<<i),1));
                }
            }
            curr=min(curr,best);
        }
    }
    
    return curr;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    while (true){
        for (int i=0;i<10;++i) cin >> p1[i];
        if (p1[0]=="*") break;
        set<string> s={"R1","R2","R3","R4","R5",
                       "Y1","Y2","Y3","Y4","Y5",
                       "G1","G2","G3","G4","G5",
                       "B1","B2","B3","B4","B5"};
        for (int i=0;i<10;++i) s.erase(p1[i]);
        int temp=0;
        for (string x:s) p2[temp++]=x;
        ms(dp,-1); dp[0][0][0]=dp[0][0][1]=0;
        // cout << solve(15,15,0) << '\n';
        // cout << dp[7][7][0] << '\n';
        cout << solve(MAXN-1,MAXN-1,0) << '\n';
    }
}