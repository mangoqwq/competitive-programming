#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int,int> cnt;
        map<int,int> idx;
        for (int i=1;i<=n;++i){
            int a; cin >> a;
            cnt[a]++;
            idx[a]=i;
        }
        for (auto [x,c]:cnt) if (c==1) cout << idx[x] << '\n';
    }
}