#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int v[31];
int dp[31][3001][2];

int solve(int i, int sum, int flag, int base){
    if (i==0) return sum==0;
    int &curr=dp[i][sum][flag];
    if (curr!=-1) return curr;
    curr=0;
    int r=(flag?v[i]:base-1);
    r=min(r,sum);
    for (int j=0;j<=r;++j){
        curr+=solve(i-1,sum-j,flag&&(j==v[i]),base);
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (1){
        int a, b, c; cin >> a >> b >> c;
        if (b==0) break;
        ms(v,0); ms(dp,-1);
        for (int i=1;i<=30;++i){
            v[i]=a%b; a/=b;
        }
        if (c>=3000) cout << 0 << '\n';
        else cout << solve(30,c,1,b) << '\n';
    }
}