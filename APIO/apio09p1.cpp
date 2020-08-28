#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1501;

int arr[MAXN][MAXN],r,c,k;

int get(int i, int j){
    return arr[i][j]-arr[i-k][j]-arr[i][j-k]+arr[i-k][j-k];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> k;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> arr[i][j];
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for (int go=1;go<=3;++go){
        ms(dp,0);
        for (int i=k;i<=r;++i){
            for (int j=k;j<=c;++j){
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],get(i,j)+last[i-k][j-k]});
            }
        }
    }
    cout << dp[r][c] << '\n';
}