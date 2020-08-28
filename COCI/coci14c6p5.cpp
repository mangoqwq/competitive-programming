#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

struct Item{int x,c;} s[MAXN];
int grid[MAXN][MAXN],ans,last[MAXN];

bool check(int i, int j){
    if (i==1||j==1) return 0;
    return (grid[i][j]+grid[i-1][j-1]<=grid[i-1][j]+grid[i][j-1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c; cin >> r >> c;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> grid[i][j];
        }
    }
    for (int i=1;i<=r;++i){
        int p=2,d,old; s[1]={0,1};
        for (int j=1;j<=c;++j){
            if (!check(i,j)) last[j]=i;
            d=i-last[j];
            old=j;
            while (p!=1&&s[p-1].x>d) ans=max(ans,(s[p-1].x+1)*(j-s[p-1].c+1)), old=s[p-1].c, p--;
            s[p]={d,old}; p++; 
        }
        while (p!=1) ans=max(ans,(s[p-1].x+1)*(c+1-s[p-1].c+1)), p--;
    }
    cout << ans << '\n';
}