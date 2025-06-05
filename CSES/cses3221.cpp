#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template<typename T>
struct Sliding {
	const T e = numeric_limits<T>::max();
	T op(T x, T y) { return min(x, y); }

	std::vector<T> a, acc, b;
	T val_b;
	Sliding() { val_b = e; }
	void push_back(T x) {
		b.push_back(x);
		val_b = op(val_b, x);
	}
	void pop_front() {
		if (a.empty()) {
			ranges::reverse(b);
			a = b;
			b.clear();
			acc.resize(a.size());
			partial_sum(a.begin(), a.end(), acc.begin(), [&](T x, T y) {
				return op(x, y);
			});
			val_b = e;
		}
		a.pop_back();
		acc.pop_back();
	}
	T val() {
		if (acc.empty()) return val_b;
		return op(val_b, acc.back());
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	int x, m, b, c; cin >> x >> m >> b >> c;
	vector<int> a(N);
	a[0] = x;
	for (int i = 1; i < N; ++i) {
		a[i] = (1LL * a[i - 1] * m + b) % c;
	}

	Sliding<int> ds;
	for (int i = 0; i < K; ++i) {
		ds.push_back(a[i]);
	}
	vector<ll> ans(N - K + 1);
	ans[0] = ds.val();
	for (int i = 0; i < N - K; ++i) {
		ds.push_back(a[i + K]);
		ds.pop_front();
		ans[i + 1] = ds.val();
	}
	ll ret = accumulate(ans.begin(), ans.end(), 0LL, [&](ll a, ll b) { return a ^ b; });
	cout << ret << '\n';
}
