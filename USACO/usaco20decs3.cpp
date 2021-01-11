#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

struct Cow{
    char dir; int x, y, id;
    bool operator<(const Cow &a) const{
        return y<a.y;
    }
} a[MAXN];
set<Cow> s;
int blame[MAXN];

bool cmp(Cow a, Cow b){ return make_pair(a.x,a.y)<make_pair(b.x,b.y); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i].dir >> a[i].x >> a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i){
        if (a[i].dir=='E'){ s.insert(a[i]); continue; }
        vector<Cow> bad;
        for (Cow x:s){
            if (a[i].y>x.y) continue;
            int t1=x.y-a[i].y, t2=a[i].x-x.x;
            if (t1<t2) bad.push_back(x), blame[a[i].id]+=blame[x.id]+1;
            else if (t1>t2){ blame[x.id]+=blame[a[i].id]+1; break; }
        }
        for (Cow x:bad) s.erase(x);
    }
    for (int i=1;i<=n;++i) cout << blame[i] << '\n';
}