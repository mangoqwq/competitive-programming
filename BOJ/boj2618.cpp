#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1002;

int n, w;
int dp[MAXN][MAXN], h[MAXN][MAXN];
pair<int,int> last[MAXN][MAXN];
int x[MAXN], y[MAXN];

int dist(int i, int j){ return abs(x[i]-x[j])+abs(y[i]-y[j]); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> w; w++;
    x[0]=y[0]=1; x[1]=y[1]=n;
    h[1][0]=1;
    ms(dp,0x3f), dp[1][0]=0;
    for (int i=2;i<=w;++i){
        cin >> x[i] >> y[i];
        for (int j=0;j<i-1;++j){
            if (dp[i-1][j]+dist(i-1,i)<dp[i][j]){
                dp[i][j]=dp[i-1][j]+dist(i-1,i);
                h[i][j]=h[i-1][j];
                last[i][j]={i-1,j};
            }
            if (dp[i-1][j]+dist(i,j)<dp[i][i-1]){
                dp[i][i-1]=dp[i-1][j]+dist(i,j);
                h[i][i-1]=!h[i-1][j];
                last[i][i-1]={i-1,j};
            }
        }
    }
    int ans=0;
    for (int i=0;i<w;++i) if (dp[w][i]<dp[w][ans]) ans=i;
    cout << dp[w][ans] << '\n';
    vector<int> vec;
    for (int i=w,x=w,y=ans;i>1;--i){
        vec.push_back(h[x][y]+1);
        tie(x,y)=last[x][y];
    }
    for (int i=vec.size()-1;i>=0;--i) cout << vec[i] << '\n';
}