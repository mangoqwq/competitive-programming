#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int ans[MAXN], pos[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int T=1;T<=t;++T){
        cout << "Case #" << T << ": ";
        int n, c; cin >> n >> c;
        c-=n-1;
        if (c<0||c>(n-1)*(n)/2){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        iota(pos+1,pos+1+n,1);
        for (int i=1;i<=n-1;++i){
            int j=min(n,i+c);
            c-=j-i;
            ans[pos[j]]=i;
            for (int l=i,r=j;l<r;++l,--r)
                swap(pos[l],pos[r]);
        }
        ans[pos[n]]=n;
        for (int i=1;i<=n;++i) cout << ans[i] << " ";
        cout << '\n';
    }
}