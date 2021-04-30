#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501, MAXV=25001;

int a[MAXN];
unordered_set<int> in;
bitset<MAXV> last, dp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n,greater<int>());
    dp[0]=1;
    for (int i=2;i<=n;++i){
        last=dp;
        for (int j:in){
            int v=j-a[i];
            dp|=last<<v;
        }
        in.insert(a[i]);
    }
    for (int i=0;i<MAXV;++i) if (dp[i]) cout << i << " ";
    cout << '\n';
}