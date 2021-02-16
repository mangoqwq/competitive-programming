#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    for (int i=1;i<n;++i) s2=(char)0+s2;
    int k; cin >> k;
    for (int i=1;i<=k;++i) s1=(char)0+s1;
    for (int i=0;i<max(s1.size(),s2.size());++i){
        if (i<s1.size()) if (s1[i]!=0) cout << s1[i];
        if (i<s2.size()) if (s2[i]!=0) cout << s2[i];
    }
    cout << '\n';
}