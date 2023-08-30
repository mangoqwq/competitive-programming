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
	ll A, B, C, K; cin >> A >> B >> C >> K;
	ll sum = 0;
	{
		ll take = min(K, A);
		sum += take;
		K -= take;
	}
	{
		ll take = min(K, B);
		K -= take;
	}
	sum -= K;
	cout << sum << '\n';
}
