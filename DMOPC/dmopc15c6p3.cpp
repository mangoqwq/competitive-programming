#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int pre[MAXN],p[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; ll k; cin >> n >> m >> k;
    for (int i=1,l,r;i<=m;++i){
        cin >> l >> r;
        pre[l]--; pre[r+1]++;
    }
    for (int i=1;i<=n;++i) pre[i]=pre[i-1]+pre[i];
    for (int i=1;i<=n;++i) pre[i]+=m;
    int ans=0x3f3f3f3f,pl=1; ll tot=0;
    for (int pr=1;pr<=n;++pr){
        tot+=pre[pr];
        while (tot-pre[pl]>=k) tot-=pre[pl],pl++;
        if (tot>=k) ans=min(ans,pr-pl+1); 
    }
    cout << (ans==0x3f3f3f3f?-1:ans) << '\n';
}