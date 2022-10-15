#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll ans,n; cin >> n;
    ans=(n+1)/2;
    ll temp=1;
    while (temp*temp<=n){
        ans--; temp+=2;
    }
    cout << ans << '\n';
}