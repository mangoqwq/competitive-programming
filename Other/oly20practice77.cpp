#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e5+1;

char arr[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int ll=0,rr=0;
    for (int i=1;i<=n;++i) cin >> arr[i], rr+=arr[i]=='R';
    int ans=0x3f3f3f3f;
    for (int i=1;i<=n;++i){
        if (arr[i]=='R') rr--;
        ans=min(ans,ll+rr);
        if (arr[i]=='L') ll++;
    }
    cout << ans << '\n';

}