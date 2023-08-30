#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	set<int> s;
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		s.insert(x);
	}
	cout << (s.size() == N ? "YES" : "NO") << '\n';
}
