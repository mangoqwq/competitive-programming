#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; ++i) q.push(i);
    for (int i = 1; i <= N; ++i){
        q.push(q.front()); q.pop();
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}
