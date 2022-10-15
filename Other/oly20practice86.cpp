#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

vector<int> arr[MAXN];
vector<int> uwu;
int dp[MAXN];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,op,x,index=0; cin >> n;
    ms(dp,-1);
    for (int _=0;_<n;++_){
        cin >> op >> x;
        if (op==0){
            if (x>=dp[index]){
                dp[++index]=x;
                arr[index].push_back(x);
                uwu.push_back(index);
            }
            else{
                int pos=upper_bound(dp,dp+index,x)-dp;
                dp[pos]=x;
                arr[pos].push_back(x);
                uwu.push_back(pos);
            }
        }
        if (op==1){
            while (uwu.size()>x){
                int temp=uwu.back(); uwu.pop_back();
                arr[temp].pop_back();
                if (!arr[temp].empty()) dp[temp]=arr[temp].back();
                else dp[temp]=-1, index--;
            }
        }
        cout << index << '\n';
    }
}
