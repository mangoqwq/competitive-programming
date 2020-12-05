#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

bool check(ll x, int y){
    for (int i=y;i>=2;--i){
        if (x-i>=0&&x-i!=1) x-=i;  
    }
    return x==0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll x, ans=1; cin >> x; x--;
        if (x==0){ cout << 1 << '\n'; continue; }
        if (x==1){ cout << 3 << '\n'; continue; }
        int lo=0, hi=2001, mid;
        while (lo<hi){
            int mid=lo+hi>>1;
            if (check(x,mid)) hi=mid;
            else lo=mid+1;
        }
        cout << lo << '\n';
    }
}