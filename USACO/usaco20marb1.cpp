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
    char a;
    int prev=0;
    int first=0x3f3f3f3f,last=-0x3f3f3f3f;
    vector<int> arr;
    for (int i=1;i<=n;++i){
        cin >> a;
        if (a=='1'){
            if (prev!=0){
                arr.push_back(i-prev);
            }
            prev=i;
            first=min(first,i);
            last=max(i,last);
        }
    }
    if (arr.empty()){
        if (first==0x3f3f3f3f){
            cout << n-1 << '\n';
            return 0;
        }
        cout << max({min(n-last,first-1),(first-1)/2,(n-first)/2}) << '\n';
        return 0;
    }
    sort(begin(arr),end(arr));
    int s=arr.size()-1;
    int ans=-0x3f3f3f3f;
    ans=max(ans,min(first-1,max(arr[s],first-1)/2));
    ans=max(ans,min(n-last,max(arr[s],n-last)/2));
    ans=max(ans,arr[s-1]/2);
    ans=max(ans,arr[s]/3);
    cout << min(ans,arr[0]) << '\n';
    
}