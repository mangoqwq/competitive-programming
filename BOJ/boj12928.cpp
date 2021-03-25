#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

bool dp[MAXN][51];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, s; cin >> n >> s; n-=2;
    dp[0][0]=1;
    int tot=0;
    for (int i=1;i<=n;++i){
        tot+=i;
        for (int j=tot;j<=s;++j){
            for (int k=i;k<=n;++k){
                if (dp[j-tot][k-i]) dp[j][k]=1;
            }
        }
    }
    cout << dp[s][n] << '\n';
}