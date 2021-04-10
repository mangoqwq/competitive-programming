#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int n=s.size(); s=" "+s;
        bool ree=(n%2)&(s[(n+1)/2]=='?'), invalid=0;
        for (int i=1;i<=n;++i){
            if (s[i]=='?'&&s[n-i+1]!='?') s[i]=s[n-i+1];
            if (s[i]!='?'&&s[n-i+1]!='?'&&s[i]!=s[n-i+1]) invalid=1;
            if (s[i]=='0') a--;
            if (s[i]=='1') b--;
        }
        int bad=(a%2)+(b%2);
        if (bad==2||invalid) cout << -1 << '\n';
        else if (a<0||b<0) cout << -1 << '\n';
        else if (ree&&bad!=1) cout << -1 << '\n';
        else{
            if (ree){
                if (a%2) s[(n+1)/2]='0', a--;
                else s[(n+1)/2]='1', b--;
            }
            for (int i=1;i<=n;++i){
                if (s[i]=='?'){
                    if (a) s[i]='0', s[n-i+1]='0', a-=2;
                    else s[i]='1', s[n-i+1]='1', b-=2;
                }
            }
            cout << s.substr(1) << '\n';
        }
    }
}