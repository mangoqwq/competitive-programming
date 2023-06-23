#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
consider hire a programmers and 0 artists
then we just take the a best programmers

say we know the answer for hiring a programmers and b-1 artists
so we have sets A = {hired coders}, B = {hired artists}, and S = {not hired}
now consider hiring 1 more artist (b-1 -> b)

we can either 
1) take an element of A and put into B, then take an element of S and put into A
2) put an element of S into B
pick the better of the two

proof: trust me
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int A, B, N; cin >> A >> B >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}

	struct Item {
		ll val; int idx;
		bool operator<(const Item &other) const {
			return val < other.val;
		}
	};

	priority_queue<Item> pqa;
	priority_queue<Item> pqb;
	priority_queue<Item> pqbma;
	for (int i = 0; i < N; ++i) {
		pqa.push({a[i], i});
		pqb.push({b[i], i});
	}

	vector<int> used(N);
	ll ans = 0;
	for (int i = 0; i < A; ++i) {
		auto [val, idx] = pqa.top(); pqa.pop();
		ans += val;
		used[idx] = 1;
		pqbma.push({b[idx] - a[idx], idx});
	}

	auto top = [&](priority_queue<Item> &pq) -> Item {
		while (used[pq.top().idx]) pq.pop();
		return pq.top();
	};

	for (int i = 0; i < B; ++i) {
		ll opt1 = -1e18, opt2 = -1e18;
		if (!pqbma.empty()) {
			opt1 = pqbma.top().val + top(pqa).val;
		}
		opt2 = top(pqb).val;
		if (opt1 > opt2) {
			ans += pqbma.top().val; pqbma.pop();
			auto [val, idx] = pqa.top(); pqa.pop();
			ans += val;
			used[idx] = 1;
			pqbma.push({b[idx] - a[idx], idx});
		}
		else {
			auto [val, idx] = pqb.top(); pqb.pop();
			ans += val;
			used[idx] = 1;
		}
	}
	cout << ans << '\n';
}
