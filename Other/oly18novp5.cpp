#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Item{ ll x; int idx; };
deque<Item> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    ll tot=0,ans;
    q.push_back({0,0});
    for (int i=1,a;i<=n+1;++i){
        if (i==n+1) a=0;
        else cin >> a, tot+=a;
        while (i-q.front().idx>k+1) q.pop_front();
        ans=a+q.front().x;
        while (!q.empty()&&q.back().x>=ans) q.pop_back();
        q.push_back({ans,i});
    }
    cout << tot-ans << '\n';
}