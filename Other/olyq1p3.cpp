#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int psa[MAXN], cnt[MAXN], pos[MAXN], dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    for (char &x:s) x-='a';
    s=' '+s;
    int ans=0;
    for (int c=0;c<26;++c){
        ms(dp,0x3f), ms(psa,0), ms(cnt,0), ms(pos,0);
        for (int i=1;i<=n;++i){
            psa[i]=psa[i-1];
            if (s[i]==c){
                psa[i]++;
                for (int j=0;j<26;++j){
                    ans=max(ans,psa[i]-cnt[j]-dp[j]);
                }
            }
            int j=pos[s[i]];
            dp[s[i]]=min(dp[s[i]],psa[j]-cnt[s[i]]);
            cnt[s[i]]++;
            pos[s[i]]=i;
        }
    }
    cout << ans << '\n';
}