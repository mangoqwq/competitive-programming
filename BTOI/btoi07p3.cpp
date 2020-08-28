#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6;

struct Item{ int n,idx; };
deque<Item> small,large;
vector<int> ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,c; cin >> n >> m >> c;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        while (!small.empty()&&small.back().n>=a) small.pop_back();
        while (!large.empty()&&large.back().n<=a) large.pop_back();
        small.push_back({a,i}); large.push_back({a,i});
        while (i-small.front().idx>=m) small.pop_front();
        while (i-large.front().idx>=m) large.pop_front();
        if (i>=m&&large.front().n-small.front().n<=c) ans.push_back(i-m+1);
    }
    if (ans.empty()) cout << "NONE" << '\n';
    else{
        for (int x:ans) cout << x << '\n';
    }
}