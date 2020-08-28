#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101;

ll tot,ans;
set<char> vowels={'A','E','I','O','U'};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s; s=" "+s;
    tot=1;
    for (int i=1;i<s.size();++i){
        if (s[i]=='_') tot*=3;
    }
    for (int mask=0;mask<tot;++mask){
        int curr=tot/3; ll sad=1;
        string uwu=s;
        int temp=mask;
        for (int j=1;j<uwu.size();++j){
            if (uwu[j]=='_'){
                if (temp/curr==0) uwu[j]='A', sad*=5;
                if (temp/curr==1) uwu[j]='B', sad*=20;
                if (temp/curr==2) uwu[j]='L';
                temp%=curr, curr/=3;
                
            }
        }
        bool hasl=0,flag=1;
        for (int i=1;i<uwu.size();++i){
            if (uwu[i]=='L') hasl=1;
            if (i<3) continue;
            if (vowels.count(uwu[i])==vowels.count(uwu[i-1])&&vowels.count(uwu[i])==vowels.count(uwu[i-2])) flag=0;
        }
        ans+=sad*(hasl&&flag);
    }
    cout << ans << '\n';
    
}