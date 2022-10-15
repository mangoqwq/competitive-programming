#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int dp[3][301][3][301];

int solve(int i1, int j1, int i2, int j2){
    int &curr=dp[i1][j1][i2][j2];
    if (curr!=-1) return curr;
    curr=0;
    if (i1==1&&j1==1&&i2==1&&j2==1){
        return curr;
    }
    if (i1==2) curr|=!(solve(1,j1,1,j1));
    for (int i=1;i<j1;++i){
        curr|=!(solve(i1,i,i1,j1-i));
    }
    // ignore 1
    if (i2==2) curr|=!(solve(1,j2,1,j2));
    for (int i=1;i<j2;++i){
        curr|=!(solve(i2,i,i2,j2-i));
    }
    // untouch 2
    if (i1==2) curr|=!(solve(1,j1,i2,j2));
    for (int i=1;i<=10;++i){
        if (j1>i) curr|=!(solve(i1,j1-i,i2,j2));
    }
    // untouch 1
    if (i2==2) curr|=!(solve(i1,j1,1,j2));
    for (int i=1;i<=10;++i){
        if (j2>i) curr|=!(solve(i1,j1,i2,j2-i));
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp,-1);
    int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
    cout << (solve(h1,w1,h2,w2)?'W':'L') << '\n';
}