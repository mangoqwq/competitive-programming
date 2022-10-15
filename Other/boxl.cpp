#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=6e5+5;

struct Sweep{
    int x, y1, y2, flag; // 0 is in, 1 is out, 2 is point
    bool operator<(const Sweep &a) const{
        return make_pair(x,flag)<make_pair(a.x,a.flag);
    }
};
vector<Sweep> eve;
set<int> cc; unordered_map<int,int> mp;
int bit[MAXN];

void ins(int i, int val){
    for (;i<MAXN;i+=i&-i) bit[i]+=val; 
}

int get(int i){
    int ret=0;
    for (;i>0;i-=i&-i) ret+=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,x1,x2,y1,y2;i<=n;++i){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2<x1||y2<y1) continue;
        eve.push_back({x1,y1,y2+1,0});
        eve.push_back({x2+1,y1,y2+1,1});
        cc.insert(y1); cc.insert(y2+1);
    }
    for (int i=1,x,y;i<=m;++i){
        cin >> x >> y;
        eve.push_back({x,y,y,2});
        cc.insert(y);
    }
    sort(eve.begin(),eve.end());
    int cnt=0, ans=0;
    for (int x:cc) mp[x]=++cnt;
    for (Sweep a:eve){
        if (a.flag==0){
            ins(mp[a.y1],1), ins(mp[a.y2],-1);
        }
        if (a.flag==1){
            ins(mp[a.y1],-1), ins(mp[a.y2],1);
        }
        if (a.flag==2) ans+=get(mp[a.y1])>0;//, cout << a.x << " " << a.y1 << " " << get(mp[a.y1]) <<  " | ";
    }
    cout << ans << '\n';

}