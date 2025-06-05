#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N; std::cin >> N;
	std::vector<std::vector<int>> a(N, std::vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::set<int> s;
			for (int k = 0; k < i; ++k) {
				s.insert(a[k][j]);
			}
			for (int k = 0; k < j; ++k) {
				s.insert(a[i][k]);
			}
			while (s.contains(a[i][j])) a[i][j]++;
			std::cout << a[i][j] << (j == N - 1 ? '\n' : ' ');
		}
	}
}
