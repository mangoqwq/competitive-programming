#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, s; cin >> n >> s;
        ll sum=n*(n+1)/2-s;
        ll l=sum/2+1, r=min(sum-1,n);
        cout << r-l+1 << '\n';
    }
}