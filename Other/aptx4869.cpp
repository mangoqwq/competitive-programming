#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

string s;
int i;

int typ(int idx){
    if (s[idx]=='('||s[idx]==')') return 0;
    if (s[idx]>='A'&&s[idx]<='Z') return 1;
    if (s[idx]>='a'&&s[idx]<='z') return 2;
    if (s[idx]>='0'&&s[idx]<='9') return 3;
    return -1;
}

map<string,ll> solve(){
    map<string,ll> ret, tmp;
    while (true){
        if (typ(i)==3){
            ll cnt=0;
            while (typ(i)==3) cnt*=10, cnt+=s[i++]-'0';
            for (auto [e,c]:tmp) ret[e]+=c*cnt;
            tmp.clear();
            continue;
        }
        if (!tmp.empty()){
                for (auto [e,c]:tmp) ret[e]+=c;
                tmp.clear();
        }
        if (s[i]==')'){
            return i++, ret;
        }
        else if (s[i]=='('){
            i++;
            tmp=solve();
        }
        else if (typ(i)==1){
            string formula; formula+=s[i++];
            while (typ(i)==2) formula+=s[i++];
            tmp[formula]++;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s; s='('+s+')'; i=1;
    map<string,ll> ans=solve();
    for (auto [e,c]:ans){
        cout << e;
        if (c!=1) cout << c;
    }
    cout << '\n';
}