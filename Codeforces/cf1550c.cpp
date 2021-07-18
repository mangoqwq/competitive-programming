#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int a[MAXN];
bool check(int l, int r){
    for (int i=l;i<=r;++i){
        for (int j=i+1;j<=r;++j){
            for (int k=j+1;k<=r;++k){
                if (a[i]<=a[j]&&a[j]<=a[k]) return 0;
                if (a[i]>=a[j]&&a[j]>=a[k]) return 0;
            }
        }
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> a[i];
        int l=1, ans=0;
        for (int r=1;r<=n;++r){
            while (!check(l,r)) l++;
            ans+=r-l+1;
        }
        cout << ans << '\n';
    }
}
