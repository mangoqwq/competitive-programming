#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define all arr.begin(),arr.end()
#define setmin(x,a) x=min(x,a);
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

int n,p,q,low,high,w;
int dp[MAXN][MAXN], nxt[MAXN][2];
vector<int> arr;

bool check(){
    ms(dp,0x3f);
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        nxt[i][0]=lower_bound(all,arr[i]+w)-arr.begin();
        nxt[i][1]=lower_bound(all,arr[i]+2*w)-arr.begin();
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<=p;++j){
            setmin(dp[nxt[i][0]][j+1],dp[i][j]);
            setmin(dp[nxt[i][1]][j],dp[i][j]+1);
        }
    }
    for (int j=0;j<=p;++j){
        if (dp[n][j]<=q) return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p >> q; arr.resize(n);
    for (int i=0;i<n;++i) cin >> arr[i];
    if (p+q>=n){ cout << 1 << '\n'; return 0; }
    sort(all);
    low=1,high=1e9;
    while (low<high){
        w=(low+high)>>1;
        //cout << low << " " << high << " " << w << '\n';
        if (check()) high=w;
        else low=w+1;
    }
    cout << low << '\n';
}