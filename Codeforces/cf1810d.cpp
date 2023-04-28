#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int Q; cin >> Q;
		ll l = -1e18;
		ll r = 1e18;
		while (Q--){
			int op; cin >> op;
			if (op == 1){
				ll A, B, N; cin >> A >> B >> N;
				ll nl, nr;
				if (N == 1){
					nl = 1;
					nr = A;
				}
				else{
					nl = (A-B) * (N-1) + B + 1;
					nr = (A-B) * (N-1) + A;
				}
				if (nl > r || nr < l){
					cout << 0 << " ";
				}
				else{
					cout << 1 << " ";
					l = max(l, nl);
					r = min(r, nr);
				}
			}
			if (op == 2){
				ll A, B; cin >> A >> B;
				ll N;
				if (A >= l){
					N = 1;
				}
				else{
					N = (l-B-1) / (A-B) + 1;
				}
				if ((A-B) * (N-1) + A >= r){
					cout << N << " ";
				}
				else{
					cout << -1 << " ";
				}
			}
		}
		cout << '\n';
	}();
}
