#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

struct Point{int p,v;};
bool cmp(Point a, Point b){return a.p<b.p;}
int dp[2][MAXN][MAXN]; //0 for left, 1 for right

vector<Point> arr;
int pre[MAXN];
int dist(int l, int r){
    return (abs(arr[l].p-arr[r].p));
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n; arr.push_back({-0x3f3f3f3f,-0x3f3f3f3f});
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b; 
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),cmp);
    int start;
    for (int i=1;i<=n;++i){if (arr[i].p==0) start=i; pre[i]=pre[i-1]+arr[i].v;}
    
    ms(dp,-0x3f);
    dp[0][start][start]=dp[1][start][start]=arr[start].v;
    for (int l=start;l>0;--l){
        for (int r=start;r<=n;++r){
            if (dist(l,l+1)<=dp[0][l+1][r]){
                dp[0][l][r]=max(dp[0][l+1][r]+arr[l].v-dist(l,l+1),dp[0][l][r]);
            }
            if (dist(l,r)<=dp[1][l+1][r]){
                dp[0][l][r]=max(dp[1][l+1][r]+arr[l].v-dist(l,r),dp[0][l][r]);
            }
            if (dist(l,r)<=dp[0][l][r-1]){
                dp[1][l][r]=max(dp[0][l][r-1]+arr[r].v-dist(l,r),dp[1][l][r]);
            }
            if (dist(r-1,r)<=dp[1][l][r-1]){
                dp[1][l][r]=max(dp[1][l][r-1]+arr[r].v-dist(r-1,r),dp[1][l][r]);
            }
            //cout << dp[0][l][r] << " " << dp[1][l][r] << " | ";
        }
        //cout << '\n';
    }
    int ans=-1;
    for (int l=1;l<=n;++l){
        for (int r=1;r<=n;++r){
            if (dp[0][l][r]>=0||dp[1][l][r]>=0){
                ans=max(ans,pre[r]-pre[l-1]);
            }
        }
    }
    cout << ans << '\n';

}