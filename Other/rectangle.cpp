#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

struct Coord{int x,y;};
Coord arr[MAXN];
map<pair<pair<int,int>,ll>,int> m; 

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i].x >> arr[i].y;
    for (int i=1;i<=n;++i){
        for (int k=i;k<=n;++k){
            ll x1=arr[i].x,x2=arr[k].x,y1=arr[i].y,y2=arr[k].y;
            m[{{x1+x2,y1+y2},(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)}]++;
        }
    }
    ll ans=0;
    for (auto x:m) ans+=x.second*(x.second-1);
    cout << ans/2 << '\n';
}
