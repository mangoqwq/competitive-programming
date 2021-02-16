#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k; k--;
        if (n%2==0) cout << (k)%n+1 << '\n';
        else{
            ll tmp=k/(n/2)*(n/2);
            ll pa=n-(tmp)%n;
            k=k-tmp+1;
            cout << (pa+k-1)%n+1 << '\n';
        }
    }
}