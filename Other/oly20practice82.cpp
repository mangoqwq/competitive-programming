#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

vector<int> arr;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=0,a;i<n;++i){ cin >> a; arr.push_back(a); }
    sort(arr.begin(),arr.end());
    int l,r;
    while (q--){
        cin >> l >> r;
        cout << upper_bound(arr.begin(),arr.end(),r)-lower_bound(arr.begin(),arr.end(),l) << '\n';
    }
}