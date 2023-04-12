#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N; cin >> N;

		auto query1 = [&](int x){
			cout << "+ " << x << '\n';
			cout.flush();
			int ret; cin >> ret;
			if (ret == -2) exit(0);
			return ret;
		};

		auto query2 = [&](int i, int j){
			cout << "? " << i << " " << j << '\n';
			cout.flush();
			int ret; cin >> ret;
			if (ret == -2) exit(0);
			assert(ret != -1);
			return ret;
		};

		query1(N+1);
		query1(N+2);
		vector<int> d(N+1);
		for (int i = 2; i <= N; ++i){
			d[i] = query2(1, i);
		}

		int far = max_element(d.begin()+1, d.end()) - d.begin();
		vector<int> d1(N+1);
		for (int i = 2; i <= N; ++i){
			if (i == far) continue;
			d1[i] = query2(far, i);
		}
		d1[1] = d[far];

		vector<int> p(N+1);
		for (int i = 1; i <= N; ++i){
			if (i % 2 == 1) p[i] = i/2 + 1;
			else p[i] = N - i/2 + 1;
		}

		cout << "! ";
		for (int i = 1; i <= N; ++i){
			assert(d1[i] >= 0 && d1[i] < N);
			cout << p[d1[i]+1] << ' ';
		}
		reverse(p.begin()+1, p.end());
		for (int i = 1; i <= N; ++i){
			cout << p[d1[i]+1] << (i == N ? '\n' : ' ');
		}
		cout.flush();
		int x; cin >> x;
		if (x != 1){
			exit(0);
		}
	}();
}
