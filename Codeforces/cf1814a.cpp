#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		ll N, K; cin >> N >> K;
		if (N % 2 == 0 || (N-K) % 2 == 0 || N % K == 0){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}();
}
