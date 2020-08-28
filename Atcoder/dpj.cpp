#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=302;

int n; int cnt[4];
double dp[MAXN][MAXN][MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        cnt[a]++;
    }
    double k;
    for (int c3=0;c3<=n;++c3){
        for (int c2=0;c2<=n;++c2){
            for (int c1=0;c1<=n;++c1){
                k=c1+c2+c3;
                //cout << k << " ";
                if (k==0) continue;
                dp[c1][c2][c3]+=(double)(n)/(k);
                if (c1!=0) dp[c1][c2][c3]+=((double)c1/k)*dp[c1-1][c2][c3];
                if (c2!=0) dp[c1][c2][c3]+=((double)c2/k)*dp[c1+1][c2-1][c3];
                if (c3!=0) dp[c1][c2][c3]+=((double)c3/k)*dp[c1][c2+1][c3-1];
                //cout << dp[c1][c2][c3] << " ";
            }
        }
    }
    cout << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << '\n';
}