#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N % 4 == 0){
        cout << "YES" << '\n';
        cout << N / 2 << '\n';
        for (int i = 1; i <= N; i += 4) cout << i << " " << i + 3 << " ";
        cout << '\n';
        cout << N / 2 << '\n';
        for (int i = 1; i <= N; i += 4) cout << i + 1 << " " << i + 2 << " ";
        cout << '\n';
    }
    else if (N % 4 == 3){
        cout << "YES" << '\n';
        cout << N / 2 + 1 << '\n';
        cout << 1 << " " << N - 1 << " ";
        for (int i = 2; i <= N - 2; i += 4) cout << i << " " << i + 3 << " ";
        cout << '\n';
        cout << N / 2 << '\n';
        cout << N << " ";
        for (int i = 2; i <= N - 2; i += 4) cout << i + 1 << " " << i + 2 << " ";
        cout << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
}
