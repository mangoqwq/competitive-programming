#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll lo=1, hi=2e9, mid;
    while (lo<hi){
        mid=lo+hi+1>>1;
        if (mid*(mid+1)/2>n+1) hi=mid-1;
        else lo=mid; 
    }
    cout << n-lo+1 << '\n';
}