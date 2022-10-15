#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Item{int h, idx;};
stack<Item> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    s.push({0x3f3f3f3f,1});
    for (int i=1,a;i<=n;++i){
        cin >> a;
        while (s.top().h<=a) s.pop();
        cout << i-s.top().idx << " ";
        s.push({a,i});
    }
    cout << '\n';
}