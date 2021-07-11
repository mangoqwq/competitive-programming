#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

set<pii> vis;
set<pii> g;
vector<pii> ans;
bool iszero(int x, int y){
    return (x%2==0)&&(y%2==0)&&((x+y)%4==0);
}
int get(int x, int y){
    if (iszero(x,y)) return 0;
    if (iszero(x,y-1)) return 1;
    if (iszero(x-1,y)) return 2;
    if (iszero(x-1,y-1)) return 3;
}
bool in(int x, int y){ return g.count({x,y}); }
bool bad(int x, int y){
    int typ=get(x,y);
    if (typ==0){
        if (in(x,y)&&in(x,y-2)&&in(x-2,y)) return 1;
    }
    if (typ==1){
        if (in(x,y-1)&&in(x-2,y-1)&&in(x,y+1)) return 1;
    }
    if (typ==2){
        if (in(x+1,y)&&in(x-1,y-2)&&in(x-1,y)) return 1;
    }
    if (typ==3){
        if (in(x+1,y-1)&&in(x-1,y-1)&&in(x-1,y+1)) return 1;
    }
    return 0;
}
void dfs(int x, int y){
    if (vis.count({x,y})) return;
    if (bad(x,y)) return;
    vis.insert({x,y});
    ans.push_back({x,y});
    int typ=get(x,y);
    if (typ==0){
        if (in(x,y)&&!in(x-2,y)) dfs(x,y+1); // 1
        if (in(x,y-2)&&!in(x,y)) dfs(x+1,y); // 3
        if (in(x-2,y)&&!in(x,y-2)) dfs(x-1,y-1); // 6
    }
    if (typ==1){
        if (in(x,y-1)&&!in(x,y+1)) dfs(x+1,y); // 3
        if (in(x-2,y-1)&&!in(x,y-1)) dfs(x,y-1); // 5
        if (in(x,y+1)&&!in(x-2,y-1)) dfs(x-1,y+1); // 8;
    }
    if (typ==2){
        if (in(x+1,y)&&!in(x-1,y)) dfs(x,y+1); // 1
        if (in(x-1,y-2)&&!in(x+1,y)) dfs(x+1,y-1); // 4
        if (in(x-1,y)&&!in(x-1,y-2)) dfs(x-1,y); // 7
    }
    if (typ==3){
        if (in(x+1,y-1)&&!in(x-1,y+1)) dfs(x+1,y+1); // 2
        if (in(x-1,y-1)&&!in(x+1,y-1)) dfs(x,y-1); // 5
        if (in(x-1,y+1)&&!in(x-1,y-1)) dfs(x-1,y); // 7
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int sx=inf, sy=inf;
    for (int i=1;i<=n;++i){
        int x, y; cin >> x >> y;
        g.insert({x,y});
        if (iszero(x,y)){
            if (tie(x,y)<tie(sx,sy)) sx=x, sy=y;
        }
        else{
            x--;
            if (tie(x,y)<tie(sx,sy)) sx=x, sy=y;
        }
    }
    dfs(sx,sy);
    cout << ans.size() << '\n';
    for (auto [x,y]:ans) cout << x << " " << y << '\n';
    // for (auto [x,y]:ans) cout << '(' << x << "," << y << ')' << ',';
}