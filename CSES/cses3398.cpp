#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

// Utilities to make functional graph easier to work with
// Supply successor array (0-indexed), returns two vectors of vectors
// First one is a list of all the cycles
// Second one contains a directed adjacency list with the reverse of all tree edges
// Runtime: O(N)
// Tested:
// https://cses.fi/problemset/task/1160
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> FunctionalGraph(std::vector<int> succ) {
	int N = succ.size();
	std::vector<std::vector<int>> cycles, tree_adj(N);
	std::vector<int> vis(N), cycle(N), cur;
	auto dfs = [&](auto self, int v) -> void {
		vis[v] = 1; cur.push_back(v);
		if (vis[succ[v]] == 1) {
			cycles.push_back({});
			for (int i = cur.size()-1; i >= 0; --i) {
				int x = cur[i];
				cycles.back().push_back(x);
				cycle[x] = 1;
				if (succ[v] == x) break;
			}
			reverse(cycles.back().begin(), cycles.back().end());
		}
		else if (vis[succ[v]] == 0) {
			self(self, succ[v]);
		}
		vis[v] = 2; cur.pop_back();
	};

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) dfs(dfs, i);
	}
	for (int i = 0; i < N; ++i) {
		if (cycle[i] && cycle[succ[i]]) continue;
		tree_adj[succ[i]].push_back(i);
	}
	return {cycles, tree_adj};
}

// Returns all the primes <= N
// Runtime: O(NloglogN)
std::vector<int> sieve(int N) {
	std::vector<int> prime(N+1, 1);
	std::vector<int> primes;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (!prime[i]) continue;
		primes.push_back(i);
		for (long long j = 1LL * i * i; j <= N; j += i) {
			prime[j] = 0;
		}
	}
	return primes;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N; std::cin >> N;
	auto primes = sieve(N);
	std::vector<int> a(N);
	for (int &x : a) {
		std::cin >> x;
		x--;
	}
	auto [cycles, _] = FunctionalGraph(a);
	auto lens = cycles | std::ranges::views::transform([&] (auto x) { return x.size(); });
	std::map<int, int> pf;
	for (int n : lens) {
		for (int p : primes) {
			if (n == 1) break;
			int cnt = 0;
			while (n % p == 0) {
				cnt++; n /= p;
			}
			pf[p] = std::max(pf[p], cnt);
		}
	}
	
	const int mod = 1e9 + 7;
	int ans = 1;
	for (auto [p, cnt] : pf) {
		while (cnt--) ans = (1LL * ans * p) % mod;
	}
	std::cout << ans << '\n';
}
