#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e6+1;

int arr[MAXN];
struct Mono{ int x,idx; };
deque<Mono> qs,ql; ll ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,ps=1,pl=1;i<=n;++i){
        while (!qs.empty()&&arr[i]-qs.front().x>k) ps=qs.front().idx+1, qs.pop_front();
        while (!qs.empty()&&qs.back().x>=arr[i]) qs.pop_back();
        qs.push_back({arr[i],i});
        while (!ql.empty()&&ql.front().x-arr[i]>k) pl=ql.front().idx+1, ql.pop_front();
        while (!ql.empty()&&ql.back().x<=arr[i]) ql.pop_back();
        ql.push_back({arr[i],i});
        ans+=i-max(ps,pl)+1;
    }
    cout << ans << '\n';
}