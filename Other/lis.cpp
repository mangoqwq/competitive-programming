#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int L=1'000'001;
int a[L],dp[L];


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int idx=0,lo,hi,mid;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        lo=0; hi=idx;
        while (lo<hi){
            mid = (lo+hi)/2;
            if (a>dp[mid]){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        dp[lo]=a;
        if (lo==idx) idx++;

    }
    cout << idx << '\n';
}