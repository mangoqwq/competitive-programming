#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

struct Def{ double t,a; }def[6];
int arr[MAXN];

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    double n; int m,k; cin >> n >> m >> k;
    for (int i=1;i<=k;++i){
        cin >> def[i].t >> def[i].a;
    }
    for (int i=1,s,l,x;i<=m;++i){
        cin >> s >> l >> x;
        arr[s]+=x; arr[s+l]-=x;
    }
    for (int i=0;i<MAXN;++i){
        if (i!=0) arr[i]+=arr[i-1];
        double dmg=1e9;
        for (int j=1;j<=k;++j){
            dmg=min(dmg,max(0.0,((double)arr[i]-def[j].t)*(1.0-def[j].a/100)));
        }
        //cout << dmg << " ";
        n-=dmg;
    }
    if (n<=0) cout << "Act Like A Cactus." << '\n';
    else printf("%.2f",n);

}