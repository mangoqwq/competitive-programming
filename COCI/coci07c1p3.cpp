#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")
// haha judge go brr

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;++i){
        cin >> arr[i];
    }
    arr.push_back(-0x3f3f3f3f);
    arr.push_back(0x3f3f3f3f);
    sort(arr.begin(),arr.end());
    int a,b; cin >> a >> b;
    if (a%2==0) a++;
    int idx=0;
    pii ans={0,a};
    for (int i=a;i<=b;i+=2){
        while (arr[idx+1]<i) idx++;
        //cout << i << " " << min(abs(i-arr[idx]),abs(i-arr[idx+1])) << " | ";
        ans=max(ans,make_pair(min(abs(i-arr[idx]),abs(i-arr[idx+1])),i));
    }
    cout << ans.second << '\n';
}