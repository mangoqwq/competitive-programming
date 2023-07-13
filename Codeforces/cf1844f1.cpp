#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		ll c; cin >> c;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}

		auto calc = [&](const vector<ll> &a) {
			ll ans = 0;
			for (int i = 1; i < N; ++i) {
				ans += abs(a[i] - a[i-1] - c);
			}
			return ans;
		};

		vector<ll> ans;
		if (c >= 0) {
			sort(a.begin(), a.end());
			ans = a;
		}
		else {
			sort(a.begin(), a.end(), greater<ll>());
			ll target = calc(a);
			ll base = 0;
			for (int idx = 0; idx < N; ++idx) {
				int left = N-idx;
				vector<ll> pre(left), suf(left);
				for (int i = 1; i < left; ++i) {
					pre[i] = abs(a[i] - a[i-1] - c) + pre[i-1];
				}
				for (int i = left-2; i >= 0; --i) {
					suf[i] = abs(a[i+1] - a[i] - c) + suf[i+1];
				}
				ll mov = 0;
				for (int i = left-1; i >= 1; --i) {
					ll l = (i == 0 ? 0 : pre[i-1]);
					ll r = (i == left-1 ? 0 : suf[i+1]);
					ll add1 = 0;
					if (i != 0 && i != left-1) {
						add1 = abs(a[i+1] - a[i-1] - c);
					}
					ll add2 = abs(a[0] - a[i] - c);
					ll add3 = 0;
					if (!ans.empty()) add3 = abs(a[i] - ans.back() - c);
					ll tot = l + r + add1 + add2 + add3;
					if (tot + base == target) {
						mov = i;
						break;
					}
				}
				if (!ans.empty()) {
					base += abs(a[mov] - ans.back() - c);
			
				}
				ans.push_back(a[mov]);
				a.erase(a.begin() + mov);
			}
		}
		for (int i = 0; i < N; ++i) {
			cout << ans[i] << (i == N-1 ? '\n' : ' ');
		}
	}();
}
