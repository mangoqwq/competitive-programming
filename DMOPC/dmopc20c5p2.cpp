#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const ll mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

ll n, m;
struct Point{
    ll x, y;
}; vector<Point> ans;

ll pos(ll x, ll y){
    if (n*y==m*x) return 0;
    else if (n*y<m*x) return -1;
    else return 1;
}

bool good(ll x, ll y){
    return pos(x+1,y)==-1&&pos(x,y+1)==1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    ll x=0, y=0;
    while (true){
        if (x==n&&y==m) break;
        ans.push_back({x,y});
        if (good(x+1,y)) x=x+1, y=y;
        else if (good(x,y+1)) x=x, y=y+1;
        else x=x+1, y=y+1;
    }
    cout << ans.size() << '\n';
    for (auto [a,b]:ans) cout << b+1 << " " << a+1 << '\n';
}