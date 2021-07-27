#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2001;

int a[MAXN], b[MAXN], c[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    sort(a+1,a+1+n);
    vector<int> ans;
    for (int i=1;i<=n;++i){
        int x=a[i]^b[1];
        for (int j=1;j<=n;++j){
            c[j]=x^b[j];
        }
        sort(c+1,c+1+n);
        bool good=1;
        for (int j=1;j<=n;++j){
            if (c[j]!=a[j]){
                good=0;
                break;
            }
        }
        if (good) ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout << ans.size() << '\n';
    for (int x:ans) cout << x << '\n';
}
