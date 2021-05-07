#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ms(x,a) memset(x,a,sizeof x)
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

ll tri[MAXN];
vector<int> vec;
vector<pair<int,int>> ans;

int main(){
    int k; cin >> k;
    for (int i=2;i<=5000;++i) tri[i]=tri[i-1]+i-1;
    for (int i=5000;i>=2;--i){
        while (k>=tri[i]) vec.push_back(i), k-=tri[i];
    }
    int tot=accumulate(vec.begin(),vec.end(),0);
    for (int i=2;i<=tot;++i) ans.push_back({i,i-1});
    int curr=1;
    for (int x:vec) ans.push_back({curr,curr+x-1}), curr+=x;
    cout << tot << " " << ans.size() << '\n';
    for (auto [a,b]:ans) cout << a << " " << b << '\n';
}