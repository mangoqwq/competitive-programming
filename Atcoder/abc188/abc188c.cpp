#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

vector<int> last, curr;
int val[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=(1<<n);++i){
        cin >> val[i];
        curr.push_back(i);
    }
    for (int i=1;i<=n-1;++i){
        swap(last,curr), curr.clear();
        for (int j=0;j<last.size();j+=2){
            curr.push_back(val[last[j]]>val[last[j+1]]?last[j]:last[j+1]);
        }
    }
    cout << (val[curr[0]]>val[curr[1]]?curr[1]:curr[0]) << '\n';
}