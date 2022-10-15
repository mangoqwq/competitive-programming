#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=26;

int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        char a; cin >> a;
        cnt[a-'a']++;
    }
    int ans=0;
    for (int i=0;i<26;++i) ans+=cnt[i]%2;
    cout << max(ans,1) << '\n';
}