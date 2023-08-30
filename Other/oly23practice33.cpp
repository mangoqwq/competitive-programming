#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template<typename T>
struct Combinatorics {
	vector<T> factorial, inv_factorial;
	Combinatorics(int N) : factorial(N + 1), inv_factorial(N + 1) {
		factorial[0] = inv_factorial[0] = 1;
		for (int i = 1; i <= N; ++i) {
			factorial[i] = factorial[i - 1] * i;
			inv_factorial[i] = inv_factorial[i - 1] / i;
		}
	}
	T fact(int x) {
		return factorial[x];
	}
	T choose(int n, int k) {
		return factorial[n] * inv_factorial[k] * inv_factorial[n - k];
	}
	T permute(int n, int k) {
		return factorial[n] * inv_factorial[n - k];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	Combinatorics<ll> c(N);

	auto ord = [&](auto self, int i, vector<int> &v) -> ll {
		if (i == v.size()-1) return 1;
		ll cur = (v[i]-1) * c.fact(N-i-1);
		for (int j = i+1; j < N; ++j) {
			if (v[j] > v[i]) v[j]--;
		}
		return cur + self(self, i+1, v);
	};
	ll a = ord(ord, 0, A);
	ll b = ord(ord, 0, B);
	cout << abs(a-b) << '\n';
}
