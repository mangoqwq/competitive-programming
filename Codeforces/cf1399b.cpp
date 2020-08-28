#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> candy(n+1),orange(n+1);
        int minc=0x3f3f3f3f,mino=0x3f3f3f3f;
        for (int i=1;i<=n;++i) cin >> candy[i], minc=min(minc,candy[i]);
        for (int i=1;i<=n;++i) cin >> orange[i], mino=min(mino,orange[i]);
        ll ans=0;
        for (int i=1;i<=n;++i){
            int c=candy[i]-minc,o=orange[i]-mino;
            int temp=min(c,o);
            c-=temp, o-=temp;
            ans+=temp+c+o;
        }
        cout << ans << '\n';
    }
}