#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+5;

struct fenwick{
    int arr[MAXN];
    void ins(int i){ for (;i<MAXN;i+=i&-i) arr[i]++; }
    int qry(int i){
        int ret=0;
        for (;i>0;i-=i&-i) ret+=arr[i];
        return ret;
    }
    int qry(int l, int r){
        return r-l+1-qry(r)+qry(l-1); 
    }
} bit;
ll ans;
set<int> grid[MAXN];
bool vis[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h, w, n; cin >> h >> w >> n;
    for (int i=1;i<=h;++i) grid[i].insert(w+1);
    for (int i=1;i<=n;++i){
        int r, c; cin >> r >> c;
        grid[r].insert(c);
    }
    int far=*grid[1].begin()-1;
    bool hori=1;
    for (int i=1;i<=h;++i){
        hori&=(!grid[i].count(1));
        if (hori){
            int curr=*grid[i].begin();
            ans+=curr-1;
            for (int c:grid[i]){
                if (!vis[c]) vis[c]=1, bit.ins(c);
            }
            if (curr<=far) ans+=bit.qry(curr,far);
        }
        else{
            for (int c:grid[i]){
                if (!vis[c]) vis[c]=1, bit.ins(c);
            }
            ans+=bit.qry(1,far);
        }
    }
    cout << ans << '\n';
}