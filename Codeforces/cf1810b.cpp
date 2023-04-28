#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N; cin >> N;
		if (N % 2 == 0){
			cout << -1 << '\n';
		}
		else{
			int B = __lg(N);
			cout << B << '\n';
			for (int i = B; i > 0; --i){
				if (1 & (N >> i)) cout << 2;
				else cout << 1;
				cout << (i == 1 ? '\n' : ' ');
			}
		}
	}();
}
