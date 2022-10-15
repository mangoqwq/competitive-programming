#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[101][1001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,t,l; cin >> n >> t;
    for (int skill=1;skill<=n;++skill){
        cin >> l;
        int time=0,exp=0;
        for (int j=0,a,b;j<l;++j){
            cin >> a >> b;
            time+=a; exp+=b;
            for (int i=1000;i>=time;--i){
                dp[skill][i]=max(max(dp[skill][i],dp[skill-1][i]),dp[skill-1][i-time]+exp);
            }
            for (int i=time;i>=0;--i){
                dp[skill][i]=max(dp[skill][i],dp[skill-1][i]);
            }
        }
    }
    cout << dp[n][t] << '\n';
}