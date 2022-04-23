#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int x : a){
        if (sum < x - 1){
            break;
        }
        else sum += x;
    }
    cout << sum + 1 << '\n';
}
