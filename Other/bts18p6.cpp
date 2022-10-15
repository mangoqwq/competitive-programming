#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5;

struct Parabola{
    int a, b, c;
    ll eval(ll x){
        return a*x*x+b*x+c;
    }
} f;
ll arr[MAXN][3];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    for (int i=1;i<=n;++i){
        int l, r; cin >> l >> r;
        cin >> f.a >> f.b >> f.c;
        arr[l][0]+=f.eval(0);
        arr[r+1][0]-=f.eval(r-l);
        arr[l+1][1]+=f.eval(1)-f.eval(0);
        arr[r+1][1]-=f.eval(r-l)-f.eval(r-l-1);
        arr[l+2][2]+=2*f.a;
        arr[r+1][2]-=2*f.a;
    }
    for (int i=1;i<=t;++i) arr[i][2]+=arr[i-1][2];
    for (int i=1;i<=t;++i) arr[i][1]+=arr[i][2]+arr[i-1][1];
    for (int i=1;i<=t;++i) arr[i][0]+=arr[i][1]+arr[i-1][0];
    for (int i=1;i<=t;++i) cout << arr[i][0] << " ";
}