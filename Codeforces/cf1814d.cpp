#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, K; cin >> N >> K;
		vector<ll> m(N), x(N);
		for (int i = 0; i < N; ++i){
			cin >> m[i];
		}
		for (int i = 0; i < N; ++i){
			cin >> x[i];
		}

		int ans = N;
		for (int c = 0; c < N; ++c){
			ll target = m[c] * x[c];

			struct Event{
				ll val, id, cost;
				bool operator<(const Event &other) const{ return val < other.val; }
			};
			vector<Event> eve;
			for (int i = 0; i < N; ++i){
				ll lo = target/m[i];
				ll hi = (target+m[i])/m[i];
				if (lo != 0) eve.push_back({lo*m[i], i, lo != x[i]});
				if (hi != 0) eve.push_back({hi*m[i], i, hi != x[i]});
				eve.push_back({x[i] * m[i], i, 0});
			}
			sort(eve.begin(), eve.end());

			int cur = 0, cnt = 0;
			vector<vector<int>> has(N, vector<int>(2, 0));

			auto get = [&](int id){
				if (has[id][0]) return 0;
				if (has[id][1]) return 1;
				return 0;
			};
			auto status = [&](int id){
				return has[id][0] || has[id][1];
			};
			auto ins = [&](Event e){
				auto [val, id, cost] = e;
				cur -= get(id);
				cnt -= status(id);
				has[id][cost]++;
				cur += get(id);
				cnt += status(id);
			};
			auto rem = [&](Event e){
				auto [val, id, cost] = e;
				cur -= get(id);
				cnt -= status(id);
				has[id][cost]--;
				cur += get(id);
				cnt += status(id);
			};

			int l = 0;
			for (int r = 0; r < eve.size(); ++r){
				ins(eve[r]);
				while (l <= r && eve[r].val - eve[l].val > K){
					rem(eve[l]);
					l++;
				}
				if (cnt == N){
					ans = min(ans, cur);
				}
			}
		}
		cout << ans << '\n';
	}();
}
