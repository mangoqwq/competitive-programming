#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=4005;

int psa[MAXN][3];
map<char,int> m={{'R',0},{'G',1},{'B',2}};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s; s=" "+s;
    for (int i=n;i>=1;--i){
        psa[i][m[s[i]]]++;
        for (int j=0;j<=2;++j) psa[i][j]+=psa[i+1][j];
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (s[i]==s[j]) continue;
            char o=3-m[s[i]]-m[s[j]];
            ans+=psa[j+1][o];
            if (2*j-i<=n){
                ans-=(m[s[2*j-i]]==o);
            }
        }
    }
    cout << ans << '\n';
}