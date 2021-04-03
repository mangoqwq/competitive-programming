#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501;

int deg[MAXN], baka[MAXN];
vector<pii> a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> deg[i], baka[i]=deg[i];
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            a.push_back({i,j});
        }
    }
    sort(baka+1,baka+1+n);
    bool uwu=1;
    for (int i=1;i<=n;++i){
        uwu&=baka[i]==i-1;
    }
    if (uwu){
        cout << "! 0 0" << '\n';
        cout.flush();
        return 0;
    }
    string res;
    sort(a.begin(),a.end(),[](pii x, pii y){ return abs(deg[x.first]-deg[x.second])>abs(deg[y.first]-deg[y.second]); });
    for (auto [x,y]:a){
        if (deg[x]<deg[y]) swap(x,y);
        cout << "? " << x << " " << y << '\n';
        cout.flush();
        cin >> res;
        if (res=="Yes"){
            cout << "! " << x << " " << y << '\n';
            cout.flush();
            return 0;
        }
    }
}