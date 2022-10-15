#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001001;

struct Item{ ll p,v; };
vector<Item> arr;
ll dp[1001];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1,p,v;i<=n;++i){
        cin >> p >> v;
        arr.push_back({p,v});
    }
    for (int i=1,a,b,c,d;i<=m;++i){
        cin >> a >> b >> c >> d; // times, item #, cost, # times used.
        ll p=c, v=arr[b-1].v*a;
        arr.push_back({p,v}); d--;
        for (int j=1;j<=d;j*=2){
            arr.push_back({p*j,v*j});
            d-=j;
        }
        if (d!=0) arr.push_back({p*d,v*d});
    }
    int cnt=1;
    for (Item x:arr){
        if (cnt>=n){
            for (int i=1000;i>=x.p;--i) dp[i]=max(dp[i],dp[i-x.p]+x.v);
        }
        else for (int i=x.p;i<=1000;++i) dp[i]=max(dp[i],dp[i-x.p]+x.v);
        cnt++;
    }
    cout << dp[k] << '\n';
}