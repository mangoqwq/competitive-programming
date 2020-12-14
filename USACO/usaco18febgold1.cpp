#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int n, q, cnt[MAXN], ans[MAXN], p1, p2;
struct Item{
    int dep, idx, dist;
    bool operator<(Item &x){
        return dep<x.dep;
    }
};
vector<Item> path, boots;
set<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        if (i!=1&&i!=n) path.push_back({a,i,0});
    }
    sort(path.begin(),path.end());
    s.insert(1), s.insert(n), cnt[n-1]=1, p1=n-1;
    for (int i=1;i<=q;++i){
        int a, b; cin >> a >> b;
        boots.push_back({a,i,b});
    }
    sort(boots.begin(),boots.end());
    for (Item curr:boots){
        while (p2<path.size()){
            if (path[p2].dep<=curr.dep){
                auto it=s.insert(path[p2].idx).first;
                auto itl=--s.find(path[p2].idx), itr=++s.find(path[p2].idx);
                cnt[*itr-*itl]--;
                cnt[*it-*itl]++, cnt[*itr-*it]++;
                while (!cnt[p1]) p1--;
                p2++;
            } else break;
        }
        ans[curr.idx]=curr.dist>=p1;
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';

}