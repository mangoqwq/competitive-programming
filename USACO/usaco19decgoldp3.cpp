#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int n,m,x,dist[26][26],arr[MAXN];
int dp[MAXN][26],best[MAXN],psa[MAXN][26];
bool vis[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    char aa;
    for (int i=1;i<=n;++i) cin >> aa, arr[i]=aa-'a';
    for (int i=0;i<m;++i)
        for (int j=0;j<m;++j)
            cin >> dist[i][j];
    for (int i=0;i<m;++i){
        for (int j=0;j<m;++j){
            for (int k=0;k<m;++k){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    for (int idx=1;idx<=n;++idx){
        for (int i=0;i<m;++i) psa[idx][i]=psa[idx-1][i]+dist[arr[idx]][i];
    }
    ms(dp,0x3f); ms(best,0x3f); best[0]=0;
    for (int idx=x;idx<=n;++idx){
        for (int i=0;i<m;++i){
            dp[idx][i]=min(dp[idx-1][i]+dist[arr[idx]][i],best[idx-x]-psa[idx-x][i]+psa[idx][i]);
            best[idx]=min(best[idx],dp[idx][i]);
        }
    }
    cout << best[n] << '\n';
}