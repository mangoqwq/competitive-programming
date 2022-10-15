#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int best[MAXN], ans[MAXN];
void precomp(){
    best[0]=best[1]=0;
    for (ll i=2;i<MAXN;++i){
        for (ll j=1;j*j<=i;++j){
            if (i%j) continue;
            if (j!=1) best[i]=max(best[i],best[i/j-1]+1);
            best[i]=max(best[i],best[j-1]+1);
        }
        ans[i]=1;
        for (ll j=2;j*j<=i;++j){
            if (i%j) continue;
            if (j!=2) ans[i]=max(ans[i],best[i/j-1]+1);
            ans[i]=max(ans[i],best[j-1]+1);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    precomp();
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cout << "Case #" << _ << ": ";
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}