#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

map<int,int> lg2;
int cnt[21];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i=0;i<=20;++i) lg2[(1<<i)]=i;
    int t; cin >> t;
    while (t--){
        int n, w; cin >> n >> w;
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            cnt[lg2[x]]++;
        }
        int ans=0, space;
        while (accumulate(cnt,cnt+21,0)){
            space=w;
            ans++;
            for (int i=20;i>=0;--i){
                int use=min(cnt[i],space/(1<<i));
                cnt[i]-=use;
                space-=use*(1<<i);
            }
        }
        cout << ans << '\n';
    }
}