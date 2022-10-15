#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e3+1;

int a[MAXN];
unordered_map<int,int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], cnt[a[i]]++;
    bool ans=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if ((a[i]+a[j])%2==0&&cnt.count((a[i]+a[j])/2)) ans=1;
        }
    }
    if (ans) return cout << 3 << '\n', 0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if ((a[i]+a[j])%2==0) ans=1;
        }
    }
    if (ans) return cout << 2 << '\n', 0;
    cout << 1 << '\n';
}