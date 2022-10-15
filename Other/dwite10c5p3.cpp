#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool dp[30001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t=5;
    while (t--){
        int n; cin >> n;
        memset(dp,0,sizeof dp);
        int total=0;
        dp[0]=true;
        for (int k=1,a;k<=n;++k){
            cin >> a;
            total+=a;
            for (int i=30000;i>=a;--i){
                if (dp[i-a]) dp[i]=true;
            }
        }
        int ans=0x3f3f3f3f;
        for (int i=0;i<=15000;++i){
            if (dp[i]){
                ans=min(ans,abs(total-2*i));
            }
        }
        cout << ans << '\n';
    }
}