#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+10;

int a[MAXN];
multiset<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        s.clear();
        for (int i=1;i<=n;++i) cin >> a[i];
        for (int i=2;i<=n;++i){
            s.insert(abs(a[i]-a[i-1]));
        }
        int best=inf, mid;
        for (int i=1;i<=n;++i){
            if (i==1) mid=a[2];
            else if (i==n) mid=a[n-1];
            else mid=(a[i-1]+a[i+1])>>1;
            if (i!=1) s.erase(s.lower_bound(abs(a[i]-a[i-1])));
            if (i!=n) s.erase(s.lower_bound(abs(a[i+1]-a[i])));
            if (i!=1) s.insert(abs(a[i-1]-mid));
            if (i!=n) s.insert(abs(a[i+1]-mid));
            best=min(best,*(--s.end()));
            if (i!=1) s.erase(s.lower_bound(abs(a[i-1]-mid)));
            if (i!=n) s.erase(s.lower_bound(abs(a[i+1]-mid)));
            if (i!=1) s.insert(abs(a[i]-a[i-1]));
            if (i!=n) s.insert(abs(a[i+1]-a[i]));
        }
        cout << (k?best:(*(--s.end()))) << '\n';
    }
}