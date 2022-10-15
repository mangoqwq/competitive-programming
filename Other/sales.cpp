#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=30001, MAXB=51, SZ=500;

int c[MAXN], v[MAXN];
int dp[MAXN/SZ+10][MAXB];
int ans[MAXB][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int b, n, q; cin >> b >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> c[i] >> v[i];
        for (int j=b;j>=c[i];--j) dp[i/SZ][j]=max(dp[i/SZ][j],dp[i/SZ][j-c[i]]+v[i]);
    }
    while (q--){
        int idx, val, l, r;
        cin >> idx >> val >> l >> r;
        c[idx]=val;
        ms(dp[idx/SZ],0);
        for (int i=(idx/SZ)*SZ;;++i){
            for (int j=b;j>=c[i];--j) dp[i/SZ][j]=max(dp[i/SZ][j],dp[i/SZ][j-c[i]]+v[i]);
            if ((i+1)%SZ==0) break;
        }
        ms(ans,0);
        int p=0;
        for (int i=l;i<=r;){
            for (int j=b;j;--j) ans[j][p^1]=max(ans[j][p^1],ans[j][p]);
            if (i%SZ==0&&i+SZ-1<=r){
                for (int k=0;k<=b;++k){
                    for (int j=b;j>=k;--j) ans[j][p^1]=max(ans[j][p^1],ans[j-k][p]+dp[i/SZ][k]);
                }
                i+=SZ;
            }
            else{
                for (int j=b;j>=c[i];--j) ans[j][p^1]=max(ans[j][p^1],ans[j-c[i]][p]+v[i]);
                ++i;
            }
            p^=1;
        }
        cout << ans[b][p] << '\n';
    }

}