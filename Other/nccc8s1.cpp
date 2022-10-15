#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

set<string> ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> t >> s;
    int n=s.size();
    for (int i=0;i<=n;++i){
        for (char x:t) ans.insert(s.substr(0,i)+x+s.substr(i));
        if (i!=n) for (char x:t) ans.insert(s.substr(0,i)+x+s.substr(i+1));
    }
    for (int i=0;i<n;++i){
        ans.insert(s.substr(0,i)+s.substr(i+1));
    }
    ans.erase(s);
    for (auto x:ans) cout << x << '\n';
}