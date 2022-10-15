#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=20;

struct Point{
    int x, y;
    bool operator<(Point a){ return make_pair(x,y)>make_pair(a.x,a.y); }
}; vector<Point> arr;
int l[MAXN], r[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, tot=0; cin >> n;
    for (int i=0,a;i<n;++i) cin >> l[i];
    for (int i=0,a;i<n;++i) cin >> r[i];
    for (int i=0;i<(1<<n);++i){
        int sl=0, sr=0;
        for (int j=0;j<n;++j){
            if (1&(i>>j)) sl+=l[j];
            else sr+=r[j];
        }
        arr.push_back({sl,sr});
    }
    sort(arr.begin(),arr.end());
    int high=-1, ans=0x3f3f3f3f;
    for (auto [x,y]:arr){
        if (y>high){
            if (high!=-1) ans=min(ans,x+high+2);
            high=y;
        }
    }
    cout << ans << '\n';

}