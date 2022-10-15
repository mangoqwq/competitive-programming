#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=4294967296,inv=244002641,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<ll> arr;
    ll a;
    for (int i=0;i<n;++i){
        cin >> a;
        arr.push_back((a*inv)%mod);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    ll total=0;
    for (int i=0;i<m;++i){
        total+=arr[i];
    }
    cout << total << '\n';
}