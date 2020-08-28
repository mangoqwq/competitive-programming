#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

bool empty[MAXN];
int pos[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1,a;i<=k;++i) cin >> a, empty[a]=1;
    for (int i=1,a;i<=k+1;++i) cin >> a, pos[a]=i;
    stack<int> s;
    for (int i=1;i<=n;++i){
        if (pos[i]!=0) s.push(pos[i]), pos[i]=0;
        if (empty[i]&&!s.empty()) s.pop(), empty[i]=0;
    }
    for (int i=1;i<=n;++i){
        if (pos[i]!=0) s.push(pos[i]), pos[i]=0;
        if (empty[i]&&!s.empty()) s.pop(), empty[i]=0;
    }
    cout << s.top() << '\n';
}