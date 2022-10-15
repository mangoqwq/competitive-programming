#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=26;

string m[MAXN];
char f, e;
ll last[MAXN], curr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=10;
    #ifndef ONLINE_JUDGE
    T=2;
    #endif
    for (int _=1;_<=T;++_){
        ms(curr,0);
        string s;
        int r, t; cin >> r >> t >> s;
        for (char x:s) curr[x-'A']++;
        for (int i=1;i<=r;++i){
            char a; string b; cin >> a >> b;
            m[a-'A']=b;
        }
        f=s.front(), e=s.back();
        while (t--){
            swap(last,curr);
            ms(curr,0);
            for (int i=0;i<=26;++i){
                for (char x:m[i]) curr[x-'A']+=last[i];
            }
            f=m[f-'A'].front();
            e=m[e-'A'].back();
        }
        cout << f << e << " " << accumulate(curr,curr+26,0LL) << '\n';
    }
}