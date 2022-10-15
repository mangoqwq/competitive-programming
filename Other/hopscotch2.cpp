#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<23)+2;

struct Item{ll x; int idx;};
int back[MAXN];
deque<Item> q; 
ll a,ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    q.push_back({0,0}); 
    for (int i=1;i<=n+1;++i){
        if (i==n+1) a=0;
        else cin >> a;
        while (i-q.front().idx>k) q.pop_front();
        ans=q.front().x+a;
        back[i]=q.front().idx;
        while (!q.empty()&&q.back().x>=ans) q.pop_back();
        q.push_back({ans,i});
    }
    cout << ans << '\n';
    vector<int> go;
    for (int i=back[n+1];i!=0;i=back[i]) go.push_back(i);
    reverse(go.begin(),go.end());
    for (int x:go) cout << x << " ";
}