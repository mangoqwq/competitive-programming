#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

string s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=0;i<k;++i){
        s+=i+'a';
        for (int j=i+1;j<k;++j){
            s+=i+'a';
            s+=j+'a';
        }
    }
    for (int i=0;i<n;++i) cout << s[i%(k*k)];
    cout << '\n';
}