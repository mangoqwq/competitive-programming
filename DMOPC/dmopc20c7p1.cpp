#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

struct Item{
    int cnt, a;
    bool operator<(const Item &x) const{
        return tie(cnt,a)<tie(x.cnt,x.a);
    }
};
priority_queue<Item> s;
int a[MAXN];
vector<int> idx[MAXN];
vector<pair<int,int>> ans;
int comp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=2*n;++i) cin >> a[i];
    for (int i=1;i<=2*n;++i) comp[i]=a[i];
    sort(comp+1,comp+1+2*n);
    for (int i=1;i<=2*n;++i) a[i]=lower_bound(comp+1,comp+1+2*n,a[i])-comp;
    for (int i=1;i<=2*n;++i) idx[a[i]].push_back(i);
    for (int i=1;i<=2*n;++i){
        if (idx[i].empty()) continue;
        s.push({(int)idx[i].size(),i});
    }
    int tot=0;
    while (s.size()>=2){
        auto [cnta,a]=s.top(); s.pop();
        auto [cntb,b]=s.top(); s.pop();
        cnta--, cntb--;
        int x=idx[a].back(); idx[a].pop_back();
        int y=idx[b].back(); idx[b].pop_back();
        ans.push_back({x,y});
        tot++;
        if (cnta) s.push({cnta,a});
        if (cntb) s.push({cntb,b});
    }
    if (!s.empty()){
        auto [cnt,a]=s.top(); s.pop();
        while (cnt){
            int x=idx[a].back(); idx[a].pop_back();
            int y=idx[a].back(); idx[a].pop_back();
            ans.push_back({x,y});
            cnt-=2;
        }
    }
    cout << tot << '\n';
    for (auto [a,b]:ans) cout << a << " " << b << '\n';
}