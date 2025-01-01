#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string p = "0123456789";
	for (int i = 1; i < 1e6; ++i) {
		ranges::next_permutation(p);
	}
	cout << p << '\n';
}
