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
	int N = 1000;
	vector<int> cnt(N+1);
	for (int a = 1; a <= 1000; ++a) {
		for (int b = a; a + b <= 1000; ++b) {
			for (int c = b; a + b + c <= 1000; ++c) {
				if (a * a + b * b == c * c) cnt[a + b + c]++;
			}
		}
	}
	cout << ranges::max_element(cnt) - cnt.begin() << '\n';
}
