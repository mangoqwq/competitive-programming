#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=512;

bool c[MAXN][MAXN], ans[MAXN][MAXN];
int dx[]={0,1,0,1}, dy[]={0,0,1,1};

void fill(int n, int x, int y, bool val){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            ans[i+x][j+y]=val;
        }
    }
}

int solve(int n, int x, int y, int cmd){
    if (cmd==0||cmd==1){
        int ret=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                ret+=c[i+x][j+y]!=cmd;
        return ret;
    }
    if (n==1) return ans[x][y]=c[x][y], 0;
    int tmp[4][3]={0};
    for (int i=0;i<4;++i){
        for (int j=0;j<3;++j){
            tmp[i][j]=solve(n/2,x+dx[i]*n/2,y+dy[i]*n/2,j);
        }
    }
    int best=0x3f3f3f3f, black=0, white=0;
    for (int i=0;i<4;++i){
        for (int j=0;j<4;++j){
            if (i==j) continue;
            int curr=0;
            for (int k=0;k<4;++k){
                if (k==i) curr+=tmp[k][0];
                else if (k==j) curr+=tmp[k][1];
                else curr+=tmp[k][2];
            }
            if (curr<best) best=curr, black=i, white=j;
        }
    }
    fill(n/2,x+dx[black]*n/2,y+dy[black]*n/2,0);
    fill(n/2,x+dx[white]*n/2,y+dy[white]*n/2,1);
    return best;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            char a; cin >> a;
            c[i][j]=a=='1';
        }
    }
    cout << solve(n,1,1,2) << '\n';
    for (int i=1;i<=n;cout << '\n', ++i){
        for (int j=1;j<=n;++j){
            cout << ans[i][j];
        } 
    }
}