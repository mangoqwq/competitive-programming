#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

vector<string> v;
string tmp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (char a='a';a<='z';++a)
        tmp=a, v.push_back(tmp);
    for (char a='a';a<='z';++a)
        for (char b='a';b<='z';++b)
            tmp=string(1,a)+b, v.push_back(tmp);
    for (char a='a';a<='z';++a)
        for (char b='a';b<='z';++b)
            for (char c='a';c<='z';++c)
                tmp=string(1,a)+b+c, v.push_back(tmp);
    for (int i=0;i<n;++i){
       cout << v[i] << " ";
    }
}