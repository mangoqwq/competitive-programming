#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001, lim=1e6;

int a[2*MAXN], n, k;

bool check(int x){
    for (int s=0;s<n;++s){
        int pos=-inf, cnt=0;
        for (int i=1;i<=n;++i){
            if (a[s+i]-pos>x) cnt++, pos=a[s+i]+x;
        }
        if (cnt<=k) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], a[i+n]=a[i]+lim;
    sort(a+1,a+1+2*n);
    cin >> k;
    int lo=0, hi=lim;
    while (lo<hi){
        int mid=lo+hi>>1;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}