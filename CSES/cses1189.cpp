#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
let fi be the amount of food that flows from i to i+1 (or N-1 to 0)
fi could be negative, if i+1 gives i food
note u never want both i give to i+1 and i+1 give to i

say table was not circular, then we can find min steps easily
let di = ai - bi (any indice's "demand")
then fi is |sum(d0 + ... + di)|, and ans is sum of fi

now consider the circular table
fix c to be the flow from N-1 to 0
then our new flow values become fi' = |sum(d0 + ... + di) - c|, and ans is sum of fi'
so its optimal to take c = median({f0 ... f_{N-2}})
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<ll> v(N);
	for (int i = 0; i < N; ++i) {
		int b; cin >> b;
		v[i] = a[i] - b;
		if (i) v[i] += v[i-1];
	}

	sort(v.begin(), v.end());
	ll c = v[N/2];
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += abs(v[i] - c);
	}
	cout << ans << '\n';
}
