#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int dp[501][30001];
int arr[30001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        memset(dp,0,sizeof dp);
        memset(arr,0,sizeof arr);
        int n,k,w; cin >> n >> k >> w;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            arr[i]+=arr[i-1];
        }
        for (int i=1;i<=k;++i){
            for (int j=1;j<=n;++j){
                dp[i][j]=max(dp[i][j-1],dp[i-1][max(0,j-w)]+arr[min(j+w-1,n)]-arr[j-1]);
                //cout << dp[i][j] << " ";
            }
            //cout << '\n';
        }
        cout << dp[k][n] << '\n';
    }
}