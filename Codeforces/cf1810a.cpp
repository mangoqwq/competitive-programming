#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N; cin >> N;
		bool good = 0;
		for (int i = 1; i <= N; ++i){
			int x; cin >> x;
			if (x <= i) good = 1;
		}
		cout << (good ? "YES" : "NO") << '\n';
	}();
}
