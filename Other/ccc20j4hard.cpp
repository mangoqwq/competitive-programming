#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e7+5;

int pi[MAXN], pir[MAXN], p=0;
char a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string t, s; cin >> t >> s;
    int n=t.size(), m=s.size();
    for (int i=0;i<m;++i) a[++p]=s[i];
    a[++p]='|';
    for (int i=0;i<n;++i) a[++p]=t[i];
    p=0;
    for (int i=m-1;i>=0;--i) b[++p]=s[i];
    b[++p]='|';
    for (int i=n-1;i>=0;--i) b[++p]=t[i];
    for (int i=2;i<=p;++i){
        pi[i]=pi[i-1];
        while (pi[i]>0&&a[i]!=a[pi[i]+1]) pi[i]=pi[pi[i]];
        if (a[i]==a[pi[i]+1]) pi[i]++;
        pir[i]=pir[i-1];
        while (pir[i]>0&&b[i]!=b[pir[i]+1]) pir[i]=pir[pir[i]];
        if (b[i]==b[pir[i]+1]) pir[i]++;
    }
    bool ans=0;
    for (int i=m;i<=n;++i){
        ans|=pi[m+1+i]+pir[p-i+m]>=m;
    }
    cout << (ans?"yes":"no") << '\n';
}