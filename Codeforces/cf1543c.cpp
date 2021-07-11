#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int cnt(long double a, long double b, long double c){
    int ret=0;
    if (a>-1) ret++;
    if (b>-1) ret++;
    if (c>-1) ret++;
    return ret;
}

void solve(long double a, long double b, long double c, long double v, long double chance, long double &ans, int turn=1){
    if (a>-1){
        long double nxt=chance*a;
        long double d=fmin(a,v)/cnt(-inf,b,c);
        solve(a-v<=1e-7?-inf:a-v,b+d,c+d,v,nxt,ans,turn+1);
    }
    if (b>-1){
        long double nxt=chance*b;
        long double d=fmin(b,v)/cnt(a,-inf,c);
        solve(a+d,b-v<=1e-7?-inf:b-v,c+d,v,nxt,ans,turn+1);
    }
    ans+=c*turn*chance;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        long double a, b, c, v; cin >> a >> b >> c >> v;
        long double ans=0;
        solve(a,b,c,v,1,ans);
        cout << fixed << setprecision(14) << ans << '\n';
    }
}

/*
1
0.4998 0.4998 0.0004 0.1666
*/