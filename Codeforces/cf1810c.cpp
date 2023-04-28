#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N; ll C, D; cin >> N >> C >> D;
		map<int, int> mp;
		mp[1] = 0;
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
			mp[x]++;
		}

		ll ans = 1e18;
		int has = 0;
		for (auto [a, b] : mp){
			if (b) has++;
			ans = min(ans, (a - has) * D + (N - has) * C);
		}
		cout << ans << '\n';
	}();
}
