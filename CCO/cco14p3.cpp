#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=201;

ll arr[MAXN], arr1[MAXN], dp[MAXN][2][MAXN]; // 0 is civilian, 1 is werewolf
vector<int> acc[MAXN], def[MAXN];
int n, w, m, deg[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> w >> m;
    char cmd;
    for (int i=0,a,b;i<m;++i){
        cin >> cmd >> a >> b;
        if (cmd=='A') acc[a].push_back(b);
        if (cmd=='D') def[a].push_back(b);
        deg[b]++;
    }
    for (int i=1;i<=n;++i){ if (deg[i]==0) acc[0].push_back(i); }
    for (int node=n;node>=0;--node){
        // if not werewolf
        ms(arr,0); ms(arr1,0); arr[0]=1;
        for (int x:acc[node]){
            for (int i=0;i<=w;++i){ // prev children
                for (int k=0;k<=w-i;++k){ // curr child
                    arr1[i+k] += (dp[x][0][k]+dp[x][1][k])*arr[i];
                    arr1[i+k] %= mod;
                }
            }
            for (int i=0;i<=w;++i) arr[i]=arr1[i], arr1[i]=0;
        }
        for (int x:def[node]){
            for (int i=0;i<=w;++i){ // prev children
                for (int k=0;k<=w-i;++k){ // curr child
                    arr1[i+k] += (dp[x][0][k]+dp[x][1][k])*arr[i];
                    arr1[i+k] %= mod;
                }
            }
            for (int i=0;i<=w;++i) arr[i]=arr1[i], arr1[i]=0;
        }
        for (int i=0;i<=w;++i) dp[node][0][i]+=arr[i];

        // if werewolf
        ms(arr,0); ms(arr1,0); arr[0]=1;
        for (int x:acc[node]){
            for (int i=0;i<=w;++i){ // prev children
                for (int k=0;k<=w-i;++k){ // curr child
                    arr1[i+k] += (dp[x][0][k])*arr[i];
                    arr1[i+k] %= mod;
                }
            }
            for (int i=0;i<=w;++i) arr[i]=arr1[i], arr1[i]=0;
        }
        for (int x:def[node]){
            for (int i=0;i<=w;++i){ // prev children
                for (int k=0;k<=w-i;++k){ // curr child
                    arr1[i+k] += (dp[x][1][k])*arr[i];
                    arr1[i+k] %= mod;
                }
            }
            for (int i=0;i<=w;++i) arr[i]=arr1[i], arr1[i]=0;
        }
        for (int i=0;i<w;++i) dp[node][1][i+1]+=arr[i];
    }
    cout << dp[0][0][w] << '\n';
}