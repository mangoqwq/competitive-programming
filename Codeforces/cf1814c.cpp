#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, S1, S2; cin >> N >> S1 >> S2;
		vector<int> r(N);
		for (int i = 0; i < N; ++i){
			cin >> r[i];
		}

		vector<int> ord(N);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int i, int j){
			return r[i] > r[j];
		});
		int C1 = S1, C2 = S2;
		vector<int> ans1;
		vector<int> ans2;
		for (int i : ord){
			if (C1 <= C2){
				ans1.push_back(i);
				C1 += S1;
			}
			else{
				ans2.push_back(i);
				C2 += S2;
			}
		}
		cout << ans1.size() << (ans1.size() == 0 ? '\n' : ' ');
		for (int i = 0; i < ans1.size(); ++i){
			cout << ans1[i]+1 << (i == ans1.size()-1 ? '\n' : ' ');
		}
		cout << ans2.size() << (ans2.size() == 0 ? '\n' : ' ');
		for (int i = 0; i < ans2.size(); ++i){
			cout << ans2[i]+1 << (i == ans2.size()-1 ? '\n' : ' ');
		}

	}();
}
