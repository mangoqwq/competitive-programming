#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int first[MAXN], last[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    ms(first,0x3f);
    for (int i=1;i<=n;++i){
        int a;
        cin >> a;
        first[a]=min(first[a],i);
        last[a]=max(last[a],i);
    }
    int ans=0;
    for (int i=1;i<=m;++i){
        int a, b;
        cin >> a >> b;
        if (last[b]!=0&&first[a]!=0x3f3f3f3f&&last[b]>=first[a]) ans=max(ans,last[b]-first[a]+1);
    }
    cout << ans << '\n';
}