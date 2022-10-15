#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x,idx) (1&(x>>idx))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<15);

vector<int> arr;
int dp[MAXN];
int n;

bool check(int curr){
    vector<int> a;
    for (int i=0;i<n;++i){
        if (is(curr,i)) a.push_back(arr[i]);
    }
    bool temp1=true,temp2=true;
    for (int i=1;i<a.size();++i){
        temp1&=a[i]<=a[i-1];
        temp2&=a[i]>=a[i-1];
    }
    return temp1|temp2;
}

bool solve(int curr){
    if (dp[curr]!=-1) return dp[curr];
    if (check(curr)) return dp[curr]=false;
    bool ans=false;
    for (int i=0;i<n;++i){
        if (!is(curr,i)) continue;
        ans|=(!solve(curr-(1<<i)));
    }
    //cout << curr << ":" << ans << " | ";
    return dp[curr]=ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t=5; 
    while (t--){
        for (int _=0;_<3;++_){
            cin >> n;
            arr.clear(); ms(dp,-1);
            for (int i=0,a;i<n;++i){
                cin >> a; arr.push_back(a);
            }
            cout << (solve((1<<n)-1)?"A":"B");
        }
        cout << '\n';
    }
}