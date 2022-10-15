#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=27;

char arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
string uwu;

bool solve(int idx, int x, int y){
    if (idx>=uwu.size()) return 1;
    if (uwu[idx]!=arr[x][y]) return 0;
    vis[x][y]=1;
    bool ans=0;
    for (int i=-1;i<=1;++i){
        for (int j=-1;j<=1;++j){
            if (vis[x+i][y+j]) continue;
            ans|=solve(idx+1,x+i,y+j);
        }
    }
    vis[x][y]=0;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> arr[i][j];
        }
    }
    while (q--){
        cin >> uwu;
        bool ans=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                ans|=solve(0,i,j);
            }
        }
        cout << (ans?"good puzzle!":"bad puzzle!") << '\n';
    }
}