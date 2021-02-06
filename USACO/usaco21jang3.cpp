#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, MAXK=2e5+1;

int a[MAXK], b[MAXK];
int arr[MAXN];
struct Item{
    ll t; int v;
    bool operator<(const Item&other) const{
        return t<other.t;
    }
};
vector<Item> vis[MAXN];
int ans[MAXN], cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k, m; cin >> n >> k >> m;
    for (int i=0;i<k;++i){
        cin >> a[i] >> b[i];
    }
    for (int i=1;i<=n;++i){
        vis[i].push_back({0,i});
        arr[i]=i;
    }
    for (int i=0;i<k;++i){
        vis[arr[a[i]]].push_back({i+1,b[i]});
        vis[arr[b[i]]].push_back({i+1,a[i]});
        swap(arr[a[i]],arr[b[i]]);
    }
    vector<Item> v;
    vector<int> uwu;
    for (int i=1;i<=n;++i){
        if (ans[i]) continue;
        v.clear();
        uwu.clear();
        int temp=0;
        for (int j=arr[i];;j=arr[j]){
            uwu.push_back(j);
            if (j==i) break;
        }
        reverse(uwu.begin(),uwu.end());
        for (int j:uwu){
            for (Item x:vis[j]) v.push_back({x.t+k*temp,x.v});
            temp++;
        }
        int temp2=v.size();
        sort(v.begin(),v.end());
        for (int i=0;i<temp2;++i) v.push_back({v[i].t+temp*k,v[i].v});
        v.push_back({0x3f3f3f3f3f3f3f3f,0});
        ll l=0, r=-1, tl=0, tr=m, curr=0;
        for (int j:uwu){
            while (v[r+1].t<=tr){
                r++;
                if (cnt[v[r].v]==0) curr++;
                cnt[v[r].v]++;
            }
            while (v[l].t<tl){
                if (cnt[v[l].v]==1) curr--;
                cnt[v[l].v]--;
                l++;
            }
            ans[j]=curr;
            tl+=k, tr+=k;
        }
        for (auto x:v) cnt[x.v]=0;
    }
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
    
}