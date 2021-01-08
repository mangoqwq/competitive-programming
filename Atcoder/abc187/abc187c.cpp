#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

set<string> s;
string ans="";

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        string c; cin >> c;
        if (s.count(c)) ans=c;
        if (c[0]=='!') s.insert(c.substr(1));
        else s.insert('!'+c);
    }
    if (ans=="") cout << "satisfiable" << '\n';
    else if (ans[0]=='!') cout << ans.substr(1) << '\n';
    else cout << ans << '\n';
}