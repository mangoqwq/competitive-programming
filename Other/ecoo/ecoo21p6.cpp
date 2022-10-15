#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int a[MAXN];
int val[MAXN][MAXN];
bitset<MAXN*MAXN> dp[MAXN], last[MAXN];
int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, tar; cin >> n >> k >> tar;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i){
        ms(cnt,0);
        int curr=0;
        for (int j=i;j<=n;++j){
            curr+=cnt[a[j]]; cnt[a[j]]++;
            val[i][j]=curr;
        }
    }
    dp[1][0]=1;
    for (int i=2;i<=n;++i){
        swap(dp,last);
        int ccnt=0;
        for (int j=i-1;j>=1;--j){
            if (a[j]==a[i]) ccnt++;
            dp[j]=last[j]<<ccnt;
        }
    }
    bool ans=0;
    for (int i=1;i<=n;++i) ans|=dp[i][tar];
    cout << (ans?"happy":"not happy") << '\n';
}