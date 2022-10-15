#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    string curr;
    vector<string> ans;
    for (char x:s){
        if (curr.empty()) curr+=x;
        else if ((curr.back()=='A')+(x=='A')!=1){
            ans.push_back(curr);
            curr=""; curr+=x;
        }
        else curr+=x;
    }
    ans.push_back(curr);
    string tmp=ans.back(); ans.pop_back();
    for (string x:ans) cout << x << " ";
    cout << tmp << '\n';
}