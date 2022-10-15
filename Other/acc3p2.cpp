#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int x[MAXN],y[MAXN],xp[MAXN],yp[MAXN],n;
ll ans=LLONG_MAX;

ll solve(int a, int b){
    ll tot=0;
    for (int i=1;i<=n;++i){
        tot+=max(abs(x[i]-a),abs(y[i]-b));
    }
    return tot;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> x[i] >> y[i];
        xp[i]=x[i]+y[i]; yp[i]=x[i]-y[i];
    }
    sort(xp+1,xp+1+n); sort(yp+1,yp+1+n);
    int a=(xp[(n+1)/2]+yp[(n+1)/2])/2;
    int b=a-yp[(n+1)/2];
    ans=min(ans,solve(a,b));
    ans=min(ans,solve(a+1,b));
    ans=min(ans,solve(a,b+1));
    ans=min(ans,solve(a+1,b+1));
    cout << ans << '\n';
}