#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
solve the problem if 1 and n are not adjacent,
say this solution divides the array into k blocks b1, b2, b3, ..., bm

an observation is that the optimal answer is at most one less than m
why? if there is division with <= m-2 blocks, then splitting the block the first array element
is in will result in a division of answer m-1 for the 1 and n non-adjacent problem

now we see if we can improve our division b1, b2, ... bm
we try iterating through the beginning of the block that contains first array element
try putting the last thing in bm into the front of b1
if b1 has sum > k, try shifting some elements to b2,
if b2 then has sum > k, try shifting some elements to b3, and so on...

once the blocks become "stable" (all sums <= k), then we check if there are any empty blocks
if so, we've found a m-1 division so we are done
otherwise, we try putting the last thing in bm into the front of b1, and repeat

when do we stop? well, when a block contains none of its original elements
the first instance block bi contains none of its original elements, then it must contain 
all the original elements of block b_{i-1}, so if in the future we find an m-1 division,
we surely should have found it already (our current state is something we've seen before, just one block shifted over)
^ not too sure about this part, but it seems pretty convincing

what is the time complexity? if some element originally in block b_i moves over two blocks, then
all the elements originally in block b_{i+1} must also have moved at least one block
this means each element moves at most once -> O(N)
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, K; cin >> N >> K;

	using pll = pair<ll, ll>;
	ll cur = 0;
	int b = 1;
	vector<deque<pll>> a = {{}}; // blocks
	vector<ll> tot = {0}; // block totals
	for (int i = 0; i < N; ++i) {
		ll x; cin >> x;
		if (x + cur > K) {
			cur = 0;
			b++;
			a.push_back(deque<pll>());
			tot.push_back(0);
		}
		cur += x;
		a.back().push_back({x, b-1});
		tot.back() += x;
	}

	auto pop_back = [&](int i) -> pll {
		auto x = a[i].back();
		a[i].pop_back();
		tot[i] -= x.first;
		return x;
	};

	auto push_front = [&](int i, pll x) -> void {
		a[i].push_front(x);
		tot[i] += x.first;
	};

	ll ans = b;
	if (ans == 1) {
		cout << 1 << '\n';
		return 0;
	}

	while (true) {
		auto x = pop_back(b-1);
		push_front(0, x);
		int i = 0;
		while (true) {
			if (tot[i] <= K) break;
			int nxt = (i+1) % b;
			while (tot[i] > K) {
				auto x = pop_back(i);
				push_front(nxt, x);
				if (a[i].back().second != i) {
					cout << ans << '\n';
					return 0;
				}
			}
			i = nxt;
		}
		if (a.back().empty()) {
			cout << ans-1 << '\n';
			return 0;
		}
	}
}
