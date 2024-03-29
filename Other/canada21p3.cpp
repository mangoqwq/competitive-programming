#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s; s+='0';
        int k; cin >> k;
        string ans;
        priority_queue<char,vector<char>,greater<char>> pq;
        for (char c:s){
            while (!ans.empty()&&k&&c<ans.back()){
                pq.push(ans.back()); ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        ans.pop_back();
        while (!pq.empty()) ans.push_back(pq.top()), pq.pop();
        cout << ans << '\n';
    }
}
