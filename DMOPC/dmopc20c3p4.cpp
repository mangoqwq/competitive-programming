#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

// 8/15

int a[MAXN], ans;
int dp[MAXN][MAXN][2]; // 0 is dec, 1 is inc

int get(int l, int r){
    return a[r]-a[l-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i], a[i]+=a[i-1];
    }
    for (int i=0;i<=n;++i) for (int j=0;j<=n;++j) dp[i][j][0]=0, dp[i][j][1]=inf;
    dp[0][0][0]=0x3f3f3f3f, dp[0][0][1]=0;
    int l, r, mid;
    for (int i=1;i<=n;++i){
        for (int j=i-1;j>=0;--j){
            l=1, r=mid=n;
            while (l<r){
                mid=(l+r+1)>>1;
                if (get(j+1,i)<=dp[j][mid-1][0]) l=mid;
                else r=mid-1;
            }
            dp[i][mid][0]=max(dp[i][mid][0],get(j+1,i));
            for (int k=1;k<=n;++k) if (dp[j][k-1][0]) r=k;
            l=mid=1;
            while (l<r){
                mid=(l+r)>>1;
                if (get(j+1,i)>=dp[j][mid-1][0]) r=mid;
                else l=mid+1;
            }
            dp[i][mid][1]=min(dp[i][mid][1],get(j+1,i));
            l=1, r=n, mid=l;
            while (l<r){
                mid=(l+r)>>1;
                if (get(j+1,i)>=dp[j][mid-1][1]) r=mid;
                else l=mid+1;
            }
            dp[i][mid][1]=min(dp[i][mid][1],get(j+1,i));
        }
        for (int k=n-1;k>=1;--k){
            dp[i][k][0]=max(dp[i][k][0],dp[i][k+1][0]);
            dp[i][k][1]=min(dp[i][k][1],dp[i][k+1][1]);
        }
    }
    for (int i=1;i<=n;++i){
        if (dp[n][i][0]!=0) ans=max(ans,i);
        if (dp[n][i][1]!=inf) ans=max(ans,i);
    }
    cout << ans << '\n';
}