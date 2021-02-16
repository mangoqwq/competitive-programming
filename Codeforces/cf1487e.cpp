#include <bits/stdc++.h>
 
using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.size(); s="0"+s;
    for (int i=1;i<=n;++i) s[i]=s[i]-'0';
    int ans=0, curr=0;
    for (int i=1;i<=n;++i){
        ans+=min((n-i+1)*abs(curr-s[i]),(n-i+2)+(n-i+1)*abs(11+s[i-1]-s[i]));
        curr=s[i];
    }
    cout << ans << '\n';
}