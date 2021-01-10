#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, tot=0; cin >> n;
    for (int i=0;i<=n;i+=3) tot-=i;
    for (int i=0;i<=n;i+=5) tot-=i;
    for (int i=0;i<=n;i+=15) tot+=i;
    tot+=(n*(n+1))/2;
    cout << tot << '\n';
}