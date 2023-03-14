#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, A, B; cin >> N >> A >> B;
	string s; cin >> s;
	ll ans = 1e18;
	for (int it = 0; it < N; ++it){
		ll cur = 1LL * it * A;
		for (int i = 0; i < N/2; ++i){
			if (s[i] != s[N-i-1]){
				cur += B;
			}
		}
		ans = min(ans, cur);
		s = s + s[0];
		s = s.substr(1);
	}
	cout << ans << '\n';
}
