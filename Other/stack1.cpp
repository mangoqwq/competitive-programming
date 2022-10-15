#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

deque<string> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t,m; cin >> t >> m;
    for (int i=1;i<=t;++i){
        string uwu; cin >> uwu;
        string op; cin >> op;
        if (op=="in") q.push_back(uwu);
        else if (q.back()==uwu) q.pop_back();
        else if (m>=1&&q.front()==uwu) q.pop_front();
    }
    for (string x:q) cout << x << '\n';
}