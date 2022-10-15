#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    double ans=0;
    vector<pii> arr;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    arr.push_back(arr[0]);
    for (int i=0;i<n;++i){
        ans+=arr[i].first*arr[i+1].second;
        ans-=arr[i].second*arr[i+1].first;
    }
    cout << ceil(abs(ans)/2) << '\n';
}