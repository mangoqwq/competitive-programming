#include <bits/stdc++.h>

using namespace std; 
const int MAXN=15001, inf=0x3f3f3f3f;

struct Point{
    int x, y;
    bool operator<(const Point &a) const{
        return make_pair(x,y)<make_pair(a.x,a.y);
    }
} a[MAXN];
multiset<int> in;
int tmp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int w, h; cin >> w >> h;
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1,a+1+n);
    int pl=1, ans=0;
    for (int i=1;i<=n;++i){
        auto [x,y]=a[i];
        in.insert(y);
        while (a[pl].x<x-w) in.erase(in.find(a[pl++].y));
        int t=0;
        for (int y:in) tmp[++t]=y;
        int l=1;
        for (int j=1;j<=t;++j){
            while (tmp[l]<tmp[j]-h) l++;
            ans=max(ans,j-l+1);
        }
    }
    cout << ans << '\n';
}