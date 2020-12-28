#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v;
    for (char x:s){
        v.push_back(x);
        while (v.size()>=3){
            int i=v.size()-1;
            if (v[i-2]=='f'&&v[i-1]=='o'&&v[i]=='x'){ for (int i=1;i<=3;++i) v.pop_back(); }
            else break;
        }
    }
    cout << v.size() << '\n';
}