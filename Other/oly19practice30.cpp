#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=102;

char grid[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h,w; cin >> h >> w;
    for (int i=0;i<=h+1;++i){
        for (int j=0;j<=w+1;++j){
            grid[i][j]='#';
        }
    }
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            cin >> grid[i][j];
        }
    }
    for (int i=0;i<=h+1;++i){
        for (int j=0;j<=w+1;++j){
            cout << grid[i][j];
        }
        cout << '\n';
    }

}