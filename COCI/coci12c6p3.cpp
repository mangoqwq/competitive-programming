#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e3 + 1, MA = 2e5;

int a[MN], seen[2 * MA + 1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int goods = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        bool good = 0;
        for (int j = 1; j < i; ++j){
            if (seen[a[i] - a[j] + MA]) good = 1;
        }
        goods += good;
        for (int j = 1; j <= i; ++j){
            seen[a[i] + a[j] + MA] = 1;
        }
    }
    cout << goods << '\n';
}
