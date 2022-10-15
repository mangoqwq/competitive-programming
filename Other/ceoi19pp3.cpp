#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

struct Coord{
    int x, y;
    bool operator<(const Coord &a) const{ return make_pair(x,y)<make_pair(a.x,a.y); }
};
set<Coord> need, ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x1, y1, x2, y2, d, dx, dy;
    cin >> x1 >> y1 >> x2 >> y2 >> d;
    int dist=abs(x2-x1)+abs(y2-y1);
    if ((dist+d)%2 || d<dist){ cout << "impossible" << '\n'; return 0; }
    if (dist==d){ cout << 0 << '\n'; return 0; }
    if (dist==1){ cout << "impossible" << '\n'; return 0; }
    dx=(x2>=x1?1:-1);
    dy=(y2>=y1?1:-1);
    if (abs(x2-x1)==1 && abs(y2-y1)==1){
        if (d<6){ cout << "impossible" << '\n'; return 0; }
        need.insert({x1,y1});
        x1-=dx;
    }
    if (abs(x2-x1)<=1){
        int i;
        for (i=x1;i!=x2;i+=dx) need.insert({i,y1}), d--;
        d-=abs(y1-y2);
        for (;d>=0;d-=2,i+=dx) need.insert({i,y1}), need.insert({i,y2});
        i-=dx;
        for (int j=y1;j!=y2;j+=dy) need.insert({i,j}); 
    }
    else{
        int i;
        for (i=y1;i!=y2;i+=dy) need.insert({x1,i}), d--;
        d-=abs(x1-x2);
        for (;d>=0;d-=2,i+=dy) need.insert({x1,i}), need.insert({x2,i});
        i-=dy;
        for (int j=x1;j!=x2;j+=dx) need.insert({j,i});
    }
    for (Coord a:need){
        for (int i=a.x-1;i<=a.x+1;++i){
            for (int j=a.y-1;j<=a.y+1;++j){
                if (!need.count({i,j})) ans.insert({i,j});
            }
        }
    }
    cout << ans.size() << '\n';
    for (Coord a:ans) cout << a.x << " " << a.y << '\n';

}