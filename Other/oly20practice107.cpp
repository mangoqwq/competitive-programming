#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

map<char,char> m;
set<char> seen;
string s,t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    for (int i=0;i<s.size();++i){
        if (m.count(s[i])&&t[i]!=m[s[i]]){ cout << "No" << '\n'; return 0; }
        if (!m.count(s[i])&&seen.count(t[i])){ cout << "No" << '\n'; return 0; }
        m[s[i]]=t[i];
        seen.insert(t[i]);
    }
    cout << "Yes" << '\n';
}