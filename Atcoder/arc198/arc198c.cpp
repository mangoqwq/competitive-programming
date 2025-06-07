#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}

	if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
		cout << "No" << '\n';
		return 0;
	}

	if (N == 2) {
		if (a == b) {
			cout << "Yes" << '\n';
			cout << 0 << '\n';
			return 0;
		}
		swap(a[0], a[1]);
		a[0]--, a[1]++;
		if (a == b) {
			cout << "Yes" << '\n';
			cout << 1 << '\n';
			cout << 1 << " " << 2 << '\n';
			return 0;
		}
		cout << "No" << '\n';
		return 0;
	}

	struct Move { int i, j; };
	vector<Move> ans;
	auto act = [&](int i, int j) {
		swap(a[i], a[j]);
		a[i]--, a[j]++;
		ans.emplace_back(i, j);
	};

	for (int i = 0; i < N - 2; ++i) {
		int need = b[i] - a[i];
		while (need != 0) {
			if (need > 0) {
				int mov = min(need + 1, N - 1 - i);
				for (int j = i; j < i + mov; ++j) {
					act(j, j + 1);
				}
				act(i, i + mov);
			}
			else {
				int mov = min(abs(need) + 1, N - 1 - i);
				act(i, i + mov);
				for (int j = i + mov - 1; j >= i; --j) {
					act(j, j + 1);
				}
			}
			need = b[i] - a[i];
		}
	}
	debug(a, b);
	if (a[N - 2] < a[N - 1]) {
		act(N - 3, N - 1);
		act(N - 3, N - 2);
		act(N - 3, N - 1);
	}
	if (a[N - 2] < b[N - 2]) {
		while (a[N - 2] > b[N - 1]) {
			act(N - 3, N - 1);
			act(N - 3, N - 2);
			act(N - 3, N - 1);
			act(N - 2, N - 1);
		}
		act(N - 3, N - 1);
		act(N - 3, N - 2);
		act(N - 3, N - 1);
	}
	else {
		while (a[N - 2] > b[N - 2]) {
			act(N - 3, N - 1);
			act(N - 3, N - 2);
			act(N - 3, N - 1);
			act(N - 2, N - 1);
		}
	}
	assert(a == b);
	cout << "Yes" << '\n';
	cout << ans.size() << '\n';
	for (auto [i, j] : ans) {
		cout << i + 1 << " " << j + 1 << '\n';
	}
	debug(a, b);
}
