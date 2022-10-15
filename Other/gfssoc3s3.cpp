#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0,power=-1;
    for (int i=1;i<=n;++i){
        if (power>=9) break;
        if (i%2==1) power++;
        ans+=9*pow(10,power);
        ans%=mod;
    }
    cout << ans << '\n';
}