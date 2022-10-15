#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.size(); s=s+'0';
    int ans=0;
    for (int i=0;i<n;++i){
        if (s[i]=='2'&&s[i+1]!='5') ans++;
    }
    cout << ans << '\n';
}