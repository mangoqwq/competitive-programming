#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int seed=131,MAXN=50;
const ll mod=998244353;

bool graph[MAXN][MAXN];
ll dp[110][50][2][2][9];
int n,e,k;

ll solve(int num, int event, int shelter, int partner, int acorns){
    if (num==1) return ((event==1)&&!shelter&&!partner&&(acorns==0));
    ll &curr=dp[num][event][shelter][partner][acorns];
    if (curr!=-1) return curr;
    curr=0;
    for (int i=1;i<=n;++i){
        if (!graph[i][event]) continue;
        if (i==4&&acorns==0) continue;
        if (i==3&&!partner) continue;
        if (i==2&&!shelter) continue;
        if (i==2) curr=(curr+solve(num-1,i,0,partner,acorns-(i==4)))%mod;
        if (i==3) curr=(curr+solve(num-1,i,shelter,0,acorns-(i==4)))%mod;
        curr=(curr+solve(num-1,i,shelter,partner,acorns-(i==4)))%mod;
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> e >> k;
    char a;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> a; graph[i][j]=(a=='1');
        }
    }
    ms(dp,-1);
    cout << solve(e,n,1,1,k)%mod << '\n';
}