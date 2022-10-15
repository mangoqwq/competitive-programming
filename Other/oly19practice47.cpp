#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;
const ll lim=0x2f2f2f2f2f2f2f2f;

ll dp[2][MAXN][MAXN]; // 0 is left, 1 is right

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll L; cin >> n >> L;
    vector<ll> arr; arr.push_back(0);
    for (int i=0,a;i<n;++i){
        cin >> a; arr.push_back(a-L);
    }
    sort(arr.begin(),arr.end());
    int start=distance(arr.begin(),find(arr.begin(),arr.end(),0));
    
    ms(dp,0x2f);
    dp[0][start][start]=dp[1][start][start]=0;
    for (int l=start;l>=0;--l){
        for (int r=start;r<arr.size();++r){
            dp[0][l][r]=min(dp[0][l+1][r]+((ll)arr.size()-r+l)*(arr[l+1]-arr[l]),dp[0][l][r]);
            dp[0][l][r]=min(dp[1][l+1][r]+((ll)arr.size()-r+l)*(arr[r]-arr[l]),dp[0][l][r]);
            dp[1][l][r]=min(dp[0][l][r-1]+((ll)arr.size()-r+l)*(arr[r]-arr[l]),dp[1][l][r]);
            dp[1][l][r]=min(dp[1][l][r-1]+((ll)arr.size()-r+l)*(arr[r]-arr[r-1]),dp[1][l][r]);
        }
    }
    //cout << dp[1][1][4] << '\n';
    cout << min(dp[0][0][arr.size()-1],dp[1][0][arr.size()-1]) << '\n';

}