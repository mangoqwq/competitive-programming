#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	// cin.tie(0)->sync_with_stdio(0);

	vector<ll> fibs = {1, 1};
	for (int i = 0; fibs.back() <= 1e11; ++i){
		fibs.push_back(fibs[fibs.size()-1] + fibs[fibs.size()-2]);
	}

	vector<ll> most;
	for (int i = 0; i < fibs.size(); ++i){
		most.push_back(0);
		for (int j = i; j >= 0; j -= 2){
			most[i] += fibs[j];
		}
	}

	int T; cin >> T;
	while (T--) [&](){
		int K; cin >> K;
		using pii = pair<int, int>;
		set<pii> s;
		ll tot = 0;
		for (int i = 0; i < K; ++i){
			int x; cin >> x;
			s.insert({x, i});
			tot += x;
		}
		if (tot == 1){
			cout << "YES" << '\n';
			return;
		}

		auto it = lower_bound(fibs.begin(), fibs.end(), tot+1);
		if (*it != tot+1){
			cout << "NO" << '\n';
			return;
		}
		int N = it - fibs.begin() - 2;

		bool ans = 0;
		auto dfs = [&](auto self, int n, set<pii> s, int lst) {
			if (s.size() > n+1) return;
			if (n == -1){
				ans = 1;
				return;
			}
			if ((--s.end())->first > most[n]) return;
			set<pii> scpy = s;
			for (auto it = scpy.rbegin(); it != scpy.rend(); ++it){
				auto [x, i] = *it;
				if (x < fibs[n]) break;
				if (i == lst) continue;
				s.erase({x, i});
				if (x-fibs[n]) s.insert({x-fibs[n], i});
				self(self, n-1, s, i);
				if (ans) return;
				if (x-fibs[n]) s.erase({x-fibs[n], i});
				s.insert({x, i});
			}
		};
		dfs(dfs, N, s, -1);
		cout << (ans ? "YES" : "NO") << '\n';
	}();
}
