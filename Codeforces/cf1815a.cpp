#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N; cin >> N;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i){
			cin >> a[i];
		}

		for (int i = 1; i < N-1; ++i){
			if (a[i] < a[i-1]){
				ll diff = a[i-1] - a[i];
				a[i] += diff;
				a[i+1] += diff;
			}
		}

		for (int i = N-2; i >= 1; --i){
			if (a[i] > a[i+1]){
				ll diff = a[i] - a[i+1];
				a[i] -= diff;
				a[i-1] -= diff;
			}
		}

		bool ok = [&]() -> bool {
			for (int i = 0; i < N-1; ++i){
				if (a[i] > a[i+1]) return 0;
			}
			return 1;
		}();

		cout << (ok ? "YES" : "NO") << '\n';
	}();
}
