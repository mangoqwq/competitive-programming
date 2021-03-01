#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int cnt[10], p[]={1,10,100,1000,10000,100000};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k; cin >> k;
    fill(cnt+1,cnt+10,k);
    string s, t; cin >> s >> t;
    for (int i=0;i<4;++i){
        cnt[s[i]-'0']--;
        cnt[t[i]-'0']--;
    }
    double ans=0;
    for (int i=1;i<=9;++i){
        for (int j=1;j<=9;++j){
            s[4]=i+'0', t[4]=j+'0';
            int s1=0, s2=0;
            for (int x=1;x<=9;++x){
                int c1=0, c2=0;
                for (int y=0;y<=4;++y){
                    if (s[y]-'0'==x) c1++;
                    if (t[y]-'0'==x) c2++;
                }
                s1+=x*p[c1], s2+=x*p[c2];
            }
            if (s1<=s2) continue;
            double curr=cnt[i]/(9.0*k-8)*((i==j?cnt[j]-1:cnt[j]))/(9.0*k-9);
            ans+=curr;
        }
    }
    cout << fixed << setprecision(9) << ans << '\n';
}