#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=301;

int a[MAXN],b[MAXN];
bool dpl[90'001]; int dpg[90'001];
vector<int> c[MAXN];
set<int> s;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    fill(begin(dpg),end(dpg),-0x3f3f3f3f); dpl[0]=1; dpg[0]=0;
    int n,m,k; cin >> n >> m >> k;
    int tot=0;
    for (int i=1;i<=n;++i){
        cin >> a[i]; tot+=a[i];
        if (a[i]<k){ cout << "Impossible" << '\n'; return 0; }
    }
    for (int i=1;i<=m;++i){
        cin >> b[i];
        if (b[i]<n){
            for (int j=90'000;j>=b[i];--j) if (dpl[j-b[i]]) dpl[j]=1;
        }
        else{
            for (int j=90'000;j>=b[i];--j) dpg[j]=max(dpg[j],dpg[j-b[i]]+1);
        }
    }
    for (int i=0;i<=90'000;++i){
        if (dpg[i]>=0) c[dpg[i]].push_back(i);
    }
    int ans=0x3f3f3f3f,pl=m;
    for (int i=0;i<=m*n;++i){
        if (!dpl[i]) continue;
        while (pl+i/n>=k && pl>=0){
            for (int x:c[pl]) s.insert(x);
            pl--;
        }
        if (s.lower_bound(tot-i)==s.end()) continue;
        ans=min(ans,*s.lower_bound(tot-i)+i-tot);
    }
    if (ans==0x3f3f3f3f) cout << "Impossible" << '\n';
    else cout << ans << '\n';
}