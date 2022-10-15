#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2005;

struct Coord{
    int x, y;
    int dist(const Coord &a){
        return abs(x-a.x)+abs(y-a.y);
    }
} arr[MAXN];
int dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; n++;
    cin >> arr[0].x >> arr[0].y >> arr[1].x >> arr[1].y;
    ms(dp,0x3f), dp[0]=0;
    for (int i=2,x,y;i<=n;++i){
        cin >> x >> y; arr[i]={x,y};
        for (int j=0;j<=i-1;++j) dp[i-1]=min(dp[i-1],dp[j]+arr[j].dist(arr[i]));
        for (int j=0;j<i-1;++j) dp[j]+=arr[i-1].dist(arr[i]);
    }
    cout << *min_element(dp,dp+n) << '\n';
}