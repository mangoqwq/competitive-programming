#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    stack<pair<int, int>> s;
    s.push({0, 0});
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        while (s.top().first >= a) s.pop();
        cout << s.top().second << " ";
        s.push({a, i});
    }
    cout << '\n';
}
