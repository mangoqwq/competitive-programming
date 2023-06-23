#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
let s be original string (the one we must answer), and t be transformed string

t is the last letter of all the cyclic shifts,
we can build a string z with the first letter of all the shifts!

in fact, z = sorted t
to finish the problem, we need to disambiguate duplicate letters of z
(if 2 b's show up in z, then which b's do they correspond to in t?)

it turns out that the ith b of z corresponds to the 1th b of t
why? let s0, s1, ... be the cyclic shifts of s in order

consider two bs (which we name b #1, b #2) at indices i and j (i < j) in t
then b #1 and b #2 are endings of si and sj
move each b #1 and b #2 from back to front of si and sj to get cyclic shifts s_i' and s_j'
now s_i' < s_j', so i' < j', so b1 and b2 in order in s.

now we can reconstruct s easily
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string T; cin >> T;
	int N = T.size();
	struct Item { char c; int idx; };
	vector<Item> t;
	vector<Item> z;
	for (int i = 0; i < N; ++i) {
		t.push_back({T[i], i});
		z.push_back({T[i], i});
	}
	sort(z.begin(), z.end(), [&](Item a, Item b) {
		return tie(a.c, a.idx) < tie(b.c, b.idx);
	});

	vector<int> loc(N);
	for (int i = 0; i < N; ++i) {
		auto [c, idx] = z[i];
		loc[idx] = i;
	}

	string ans = "";
	int p = 0;
	for (int i = 0; i < N-1; ++i) {
		ans.push_back(t[p].c);
		p = loc[t[p].idx];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
