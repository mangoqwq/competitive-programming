#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define INF 0x3f3f3f3f
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll f(ll x,ll y, ll z){
    return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r,g,b; cin >> r >> g >> b;
        vector<int> red={-INF,INF},green={-INF,INF},blue={-INF,INF};
        ll ans=LLONG_MAX;
        for (int i=0,a;i<r;++i){
            cin >> a;
            red.push_back(a);
        }
        for (int i=0,a;i<g;++i){
            cin >> a;
            green.push_back(a);
        }
        for (int i=0,a;i<b;++i){
            cin >> a;
            blue.push_back(a);
        }
        sort(red.begin(),red.end());
        sort(blue.begin(),blue.end());
        sort(green.begin(),green.end());
        int tg,tb;
        for (int i=1;i<=r;++i){
            tg=upper_bound(green.begin(),green.end(),red[i])-green.begin();
            tb=upper_bound(blue.begin(),blue.end(),red[i])-blue.begin();
            cout << tg << " " << tb << " ";
            ans=min(ans,f(red[i],green[tg],blue[tb]));
            ans=min(ans,f(red[i],green[tg-1],blue[tb]));
            ans=min(ans,f(red[i],green[tg],blue[tb-1]));
            ans=min(ans,f(red[i],green[tg-1],blue[tb-1]));
        }
        cout << ans << '\n';
    }
}