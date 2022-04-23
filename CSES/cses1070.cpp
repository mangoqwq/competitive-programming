#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> ans;
    for (int i = N - 1; i >= 1; i -= 2){
        ans.push_back(i);
    }
    for (int i = N; i >= 1; i -= 2){
        ans.push_back(i);
    }
    bool can = 1;
    for (int i = 1; i < ans.size(); ++i){
        can &= abs(ans[i] - ans[i - 1]) != 1;
    }
    if (!can) cout << "NO SOLUTION" << '\n';
    else{
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}
