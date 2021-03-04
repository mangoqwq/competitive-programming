#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

bool solve(){
    string s; cin >> s;
    for (int i=0;i<=1;++i){
        for (int j=0;j<=1;++j){
            for (int k=0;k<=1;++k){
                int cnt=0;
                bool ans=1;
                for (int x=0;x<s.size();++x){
                    if (s[x]=='A') cnt+=i*2-1;
                    if (s[x]=='B') cnt+=j*2-1;
                    if (s[x]=='C') cnt+=k*2-1;
                    if (cnt<0) ans=0;
                }
                ans&=cnt==0;
                if (ans) return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cout << (solve()?"YES":"NO") << '\n';
    }
}