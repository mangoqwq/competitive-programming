#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int c1[26], c2[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    for (char x:s) c2[x-'a']++;
    int ans=0, curr=0;
    for (char x:s){
        c1[x-'a']++, c2[x-'a']--;
        if (c1[x-'a']==1) curr++;
        if (c2[x-'a']==0) curr--;
        ans=max(ans,curr);
    }
    cout << ans << '\n';
}