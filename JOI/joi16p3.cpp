#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

/*
curr = dp[i][j][k][c] = 
                dp[i-1][j-1][k-(2*(j-1)+c)*(val)][c] (new component) (j!=0) +
                dp[i-1][j][k-(2*(j)+c)*(val)][c]*(j) (add to component) +
                dp[i-1][j+1][k-(2*(j+1)+c)*(val)][c]*(j+1)*(j)*(2) (merge two components) +
                dp[i-1][j][k-(2*(j)+c-1)*(val)][c-1] (creating new end w/o merge) (c!=0) +
                dp[i-1][j+1][k-(2*(j+1)+c-1)*(val)][c-1]*(j+1)*(c==1?2:1) (creating new end w/ merge) (c!=0) +
                dp[i-1][j][k-(2*(j)+c)*(val)][c]*(c) (adding to end) +
                dp[i-1][j+1][k-(2*(j+1)+c)*(val)][c]*(j+1)*(c) (merging component to end)
val=(a[i]-a[i-1])
):
*/

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101,MAXL=1001;

ll a[MAXN],val;
ll dp[MAXN][MAXL][3], last[MAXN][MAXL][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,l; cin >> n >> l;
    for (int i=1;i<=n;++i) cin >> a[i];
    if (n==1){ cout << 1 << '\n'; return 0; }
    sort(a+1,a+1+n); a[0]=a[1];
    dp[0][0][0]=1;
    for (int i=1;i<n;++i){
        val=(a[i]-a[i-1]);
        swap(dp,last);
        for (int j=0;j<=i;++j){
            for (int k=0;k<=l;++k){
                for (int c=0;c<=2;++c){
                    ll &curr=dp[j][k][c]; curr=0;
                    if (k>=(2*(j-1)+c)*(val)){ // j-1
                        if (j!=0) curr+=last[j-1][k-(2*(j-1)+c)*(val)][c]; // new component
                    }
                    if (k>=(2*(j)+c)*(val)){  // j
                        curr+=last[j][k-(2*(j)+c)*(val)][c]*(j)*2; // add to component
                        curr+=last[j][k-(2*(j)+c)*(val)][c]*(c); // adding to end
                    }
                    if (k>=(2*(j)+c-1)*(val)&&c!=0){ // j
                        curr+=last[j][k-(2*(j)+c-1)*(val)][c-1]*(3-c); // creating new end w/o merge
                    }
                    if (k>=(2*(j+1)+c)*(val)){  // j+1
                        curr+=last[j+1][k-(2*(j+1)+c)*(val)][c]*(j+1)*(j); // merge two components
                        curr+=last[j+1][k-(2*(j+1)+c)*(val)][c]*(j+1)*(c); // merging component to end
                    }
                    if (k>=(2*(j+1)+c-1)*(val)&&c!=0){ // j+1
                        curr+=last[j+1][k-(2*(j+1)+c-1)*(val)][c-1]*(j+1)*(3-c); // creating new end w/ merge
                    }
                    curr%=mod;
                }
            }
        }
    }
    ll tot=0; val=a[n]-a[n-1];
    for (int i=2*val;i<=l;++i) tot+=dp[0][i-2*val][2];
    for (int i=val;i<=l;++i) tot+=dp[0][i-val][1];
    cout << tot%mod << '\n';
}