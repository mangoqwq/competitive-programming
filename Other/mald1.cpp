#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<string> s(N + 2);
    vector<bool> bad(N + 2);
    for (int i = 1; i <= N; ++i){
        cin >> s[i];
        if (s[i].find("yubo") != string::npos){
            bad[i - 1] = bad[i] = bad[i + 1] = 1;
        }
    }
    set<string> bads;
    for (int i = 1; i <= N; ++i){
        if (bad[i]) bads.insert(s[i]);
    }
    for (string s : bads){
        cout << s << '\n';
    }
}
