#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int egcd(int a, int b, int &x, int &y){
    if (b==0) return x=1, y=0, a;
    int x1, y1, g=egcd(b,a%b,x1,y1);
    return x=y1, y=x1-a/b*y1, g;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, s, k, x, y; cin >> n >> s >> k;
        s=n-s;
        int g=egcd(k,n,x,y);
        if (s%g!=0) cout << -1 << '\n';
        else{
            n=n/g;
            x=1LL*x*s/g%n;
            cout << (x+n)%n << '\n';
        }
    }
}