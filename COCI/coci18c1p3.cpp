#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5;

int n, m, a1[MAXN], a2[MAXN], p;

bool check(int x){
    p=1;
    for (int i=1;i<=m;++i){
        while (a2[i]-a1[p]>x) p++;
        if (a1[p]-a2[i]>x) return false;
        p++;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> a1[i];
    for (int i=1;i<=m;++i) cin >> a2[i];
    if (m>n) swap(n,m), swap(a1,a2);
    sort(a1+1,a1+1+n);
    sort(a2+1,a2+1+m);
    a1[n+1]=2e9+1;
    int lo=0, hi=1e9, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (check(mid)) hi=mid;
        else lo=mid+1; 
    }
    cout << lo << '\n';

}