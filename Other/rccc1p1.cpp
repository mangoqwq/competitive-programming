#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, c, v; cin >> n >> c >> v;
    string s; cin >> s; s=" "+s;
    int cc=0, cv=0;
    for (int i=1;i<=n;++i){
        if (s[i]=='y') cc++, cv++;
        else if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') cv++, cc=0;
        else cc++, cv=0;
        if (cc>c||cv>v) return cout << "NO" << '\n', 0;
    }
    cout << "YES" << '\n';
}