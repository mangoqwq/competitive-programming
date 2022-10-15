#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=10;
    #ifndef ONLINE_JUDGE
    T=2;
    #endif
    for (int _=1;_<=T;++_){
        int n, m, d; cin >> n >> m >> d;
        int cnt[d+1]={0};
        for (int i=1;i<=m;++i){
            int a; cin >> a;
            cnt[a]++;
        }
        int tot=n, curr=n, ans=0;
        for (int i=1;i<=d;++i){
            if (curr==0) curr=tot, ans++;
            curr+=cnt[i], tot+=cnt[i];
            curr--;
        }
        cout << ans << '\n';
    }
}