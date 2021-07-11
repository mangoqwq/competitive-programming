#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s=' '+s;
    for (int i=1;i<=20;++i) s=s+'{';
    vector<string> a[21];
    for (int i=1;i<=m;++i){
        string t; cin >> t;
        a[t.size()].push_back(' '+t);
    }
    for (int i=1;i<=20;++i) sort(a[i].begin(),a[i].end());
    vector<string> ans(n+1,"{");
    ans[0]="";
    for (int i=1;i<=n;++i){
        for (int j=1;j<=20;++j){
            for (string t:a[j]){
                bool bad=0;
                for (int k=1;k<=j;++k){
                    if (t[k]==s[i+k-1]||s[i+k-1]=='?');
                    else bad=1;
                }
                if (bad) continue;
                ans[i+j-1]=min(ans[i+j-1],ans[i-1]+t.substr(1));
                break;
            }
        }
    }
    cout << ans[n] << '\n';
}
