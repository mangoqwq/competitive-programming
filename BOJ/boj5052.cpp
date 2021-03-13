#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int trie[MAXN][10], T;
bool tail[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ms(tail,0); ms(trie,0); T=0;
        bool ans=1;
        for (int i=1;i<=n;++i){
            string s; cin >> s;
            int p=0;
            for (char &x:s){
                x=x-'0';
                if (!trie[p][x]) trie[p][x]=++T;
                p=trie[p][x];
                ans&=(!tail[p]);
            }
            for (int j=0;j<=9;++j) ans&=(!trie[p][j]);
            tail[p]=1;
        }
        cout << (ans?"YES":"NO") << '\n';
    }
}