#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int A, B; cin >> A >> B;
		int ans = 2e9 + 10;
		for (int m = 1; m <= 1e5; ++m){
			ans = min(ans, m-1 + (A+m-1)/m + (B+m-1)/m);
		}
		cout << ans << '\n';
	}();
}
