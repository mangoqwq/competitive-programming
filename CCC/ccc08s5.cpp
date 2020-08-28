#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=923521;

int dp[MAXN];

bool solve(int a, int b, int c, int d){
    if (a<0||b<0||c<0||d<0) return 1;
    int key=29791*a+961*b+31*c+d;
    if (dp[key]!=-1) return dp[key];
    bool ans=0;
    ans|=!solve(a-2,b-1,c,d-2);
    ans|=!solve(a-1,b-1,c-1,d-1);
    ans|=!solve(a,b,c-2,d-1);
    ans|=!solve(a,b-3,c,d);
    ans|=!solve(a-1,b,c,d-1);
    return dp[key]=ans;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        ms(dp,-1);
        cout << (solve(a,b,c,d)?"Patrick":"Roland") << '\n';
    }
}
