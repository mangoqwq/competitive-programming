#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

vector<ll> arr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll tot=0;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        tot+=a;
        arr.push_back(2LL*a+b);
    }
    sort(arr.begin(),arr.end(),greater<ll>());
    for (int i=1;i<=n;++i){
        tot-=arr[i-1];
        if (tot<0) return cout << i << '\n', 0;
    }
}