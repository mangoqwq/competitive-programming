#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3001;

char grid[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i=0;i<MAXN;++i) for (int j=0;j<MAXN;++j) grid[i][j]='.';
    int n; cin >> n;
    string s; cin >> s;
    int idx=1500, mn=0x3f3f3f3f, mx=0;
    s=" "+s;
    for (int i=1;i<=n;++i){
        if (s[i]=='v') grid[++idx][i]='\\', mn=min(mn,idx), mx=max(mx,idx);
        if (s[i]=='^') mn=min(mn,idx), mx=max(mx,idx), grid[idx--][i]='/';
        if (s[i]=='>') mn=min(mn,idx), mx=max(mx,idx), grid[idx][i]='_';
    }
    for (int i=mn;i<=mx;++i){
        for (int j=1;j<=n;++j){
            cout << grid[i][j];
        }
        cout << '\n';
    }

}