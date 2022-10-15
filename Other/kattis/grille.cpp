#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=11;

bool vis[MAXN][MAXN];
char g[MAXN][MAXN];
struct Point{ int x, y; };
vector<Point> lst, poi;
string s;
int cnt=0;

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            char a; cin >> a;
            if (a=='.'){
                cnt++;
                poi.push_back({i,j});
            }
        }
    }
    cin >> s; int p=0;
    if (cnt*4!=n*n) return cout << "invalid grille" << '\n', 0;
    for (int _=1;_<=4;++_){
        sort(poi.begin(),poi.end(),[](Point a, Point b){ return tie(a.x,a.y)<tie(b.x,b.y); });
        swap(lst,poi); poi.clear();
        for (auto [x,y]:lst){
            if (vis[x][y]) return cout << "invalid grille" << '\n', 0;
            vis[x][y]=1; g[x][y]=s[p++];
            poi.push_back({y,n-x+1});
        }
    }
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) cout << g[i][j];
    cout << '\n';
}