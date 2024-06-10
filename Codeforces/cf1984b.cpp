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
	int T; cin >> T;
	while (T--) [&]() {
		string N; cin >> N;
		if (N[0] != '1') {
			cout << "NO" << '\n';
			return;
		}
		string tar = "1";
		for (int i = 0; i < (int)N.length()-2; ++i) {
			tar.push_back('9');
		}
		tar.push_back('8');
		string diff = to_string(stoll(tar) - stoll(N));
		if (diff[0] == '-') {
			cout << "NO" << '\n';
		}
		else if (diff.find('9') != diff.npos) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}();
}
