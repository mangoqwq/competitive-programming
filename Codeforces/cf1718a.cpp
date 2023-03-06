#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		int ans = N, cur = 0;
		set<int> seen = {0};
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
			cur ^= x;
			if (seen.count(cur)){
				ans--;
				cur = 0;
				seen = {0};
			}
			else{
				seen.insert(cur);
			}
		}
		cout << ans << '\n';
	}
}
