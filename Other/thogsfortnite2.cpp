#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101;

int dp[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int h,n; cin >> h >> n;
    int d,a,w; cin >> d >> a >> w;
    for (int i=0;i<a;++i){
        int t,p; cin >> t >> p;
        for (int i=d;i>=t;--i) dp[i]=max(dp[i],dp[i-t]+p);
    }
    cout << dp[min(d,h)] << '\n';

}