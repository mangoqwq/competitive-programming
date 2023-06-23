#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
greedy
instead of coins, think of an operation as -1 on some grid entry
and +1 on an adjacent entry. grid entries can become negative

say we have something like
1 1 1 1 1 a ...
1 1 1 1 1 b ...
where a b is at col i
(note a, b could be negative)

what can we do to fix col i?
1) move coins (possibly 0) between a and b to get a' and b'
2) move a'-1 and b'-1 coins to col i+1

its always optimal to preform 1) as many times as possible if it makes
both entries closer to 1

why? each 1) operation costs 1, but reduces the total cost of 2) by 2
if it's a bad move, we can surely swap them back at a later column
the cost of swapping them back is at least as good as just not swapping
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N+1), b(N+1);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		int da = a[i] - 1;
		int db = b[i] - 1;
		if (da * db < 0) {
			ll del = min(abs(da), abs(db));
			if (da < 0) a[i] += del;
			else a[i] -= del;
			if (db < 0) b[i] += del;
			else b[i] -= del;
			ans += del;
		}
		ans += abs(a[i] - 1);
		ans += abs(b[i] - 1);
		a[i+1] += a[i] - 1;
		b[i+1] += b[i] - 1;
	}
	cout << ans << '\n';
}
